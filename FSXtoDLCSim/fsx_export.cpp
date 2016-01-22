#include "stdafx.h"
#include "fsx_export.h"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "4200"

using namespace std;


int quit = 0;
string sim_status;
HANDLE  hSimConnect = NULL;
ofstream myfile;

struct Struct1
{
	char    title[256];
	char	atcID[256];
	char	atcAirline[256];
	char	atcFlightNumber[256];

	double  radians;
	double  altitude;
	double	gps_altitude;
	double	radar_altitude;
	double  latitude;
	double	gps_latitude;
	double  longitude;
	double	gps_longitude;
	double	GS;
	double	TAS;
	double	IAS;
	double	DME_GPS_dist;
	double	bearing;
	double	DME_GPS_speed;
	double	TRANSPONDER_CODE;
	double	waypoint_ETE;
	char	waypoint_id[256];
};

static enum EVENT_ID
{
	EVENT_SIM_START,
	EVENT_SIM_STOP,
};

static enum DATA_DEFINE_ID 
{
	DEFINITION_1,
	DEFINITION_WAYPOINT,
};

static enum DATA_REQUEST_ID 
{
	REQUEST_1,
};

void CALLBACK MyDispatchProcRD(SIMCONNECT_RECV* pData, DWORD cbData, void *pContext)
{
	HRESULT hr;
	SIMCONNECT_DATA_WAYPOINT wp[2];
	wp[0].Flags = SIMCONNECT_WAYPOINT_SPEED_REQUESTED;
	wp[0].Altitude = 800;

	static double conversion = 57.295778; //Conversion from radians to degrees
	double degrees = 0;

	switch (pData->dwID)
	{
		case SIMCONNECT_RECV_ID_EVENT:
		{
			SIMCONNECT_RECV_EVENT *evt = (SIMCONNECT_RECV_EVENT*)pData;
			switch (evt->uEventID)
			{
				case EVENT_SIM_START:
				{
					//Now the Sim is running, request information on the user aircraft and get it to send data when plane exceeds turn
					//angle (last) argument in function SimConnect_AddToDataDefinition()
					hr = SimConnect_RequestDataOnSimObject(hSimConnect, REQUEST_1, DEFINITION_1, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_VISUAL_FRAME, SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);
					cout << "Sim sucessfully started!" << endl;	// print when flight is opened
					sim_status = "OPENED";

					break;
				}

				case EVENT_SIM_STOP:
				{
					cout << "Sim sucessfully stopped!" << endl;	// print when flight is closed			
					sim_status = "CLOSED";
				}

				default:
				{
					//cout << "Error1" << endl;	//Debug output
					break;
				}
			}
		break;
		}

		case SIMCONNECT_RECV_ID_SIMOBJECT_DATA:
		{
			SIMCONNECT_RECV_SIMOBJECT_DATA *pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;		
			switch (pObjData->dwRequestID)
			{
				case REQUEST_1:
				{
					DWORD ObjectID = pObjData->dwObjectID;
					Struct1 *pS = (Struct1*)&pObjData->dwData;
					//Waypoint_struct *pS2 = (Waypoint_struct*)&pObjData->dwData;
					degrees = pS->radians * conversion;

					if (SUCCEEDED(StringCbLengthA(&pS->title[0], sizeof(pS->title), NULL))) // security check
					{
						cout << "STATUS=" << sim_status << "\nATCID=" << pS->atcID << " Airline=" << pS->atcAirline << " FN=" << pS->atcFlightNumber << " Title=" << pS->title <<
							"\nHDG=" << degrees << " LAT=" << pS->latitude << " LON=" << pS->longitude << " ALT=" << pS->altitude << " GS=" << pS->GS << "[m/s] TAS=" << pS->TAS << "[kt] IAS=" << pS->IAS <<  "[kt] TRANSP=" <<
							pS->TRANSPONDER_CODE << " WP_ETA=" << pS->waypoint_ETE << " WP_ID: " << pS->waypoint_id << endl;

						myfile.open("FSX_data.txt", ios::trunc);

						if (myfile.is_open())
						{
							myfile << std::setprecision(20) << "STATUS=" << sim_status << "\tATC_ID=" << pS->atcID << "\tAIRLINE=" << pS->atcAirline << "\tFLIGHT_NUMBER=" << pS->atcFlightNumber << "\tTITLE=" << pS->title << "\n"
								<< "TRANSP=" << pS->TRANSPONDER_CODE << "\tHDG=" << degrees << "\tLAT=" << pS->latitude << "\tGPS_LAT=" << pS->gps_latitude << "\tLON=" << pS->longitude << "\tGPS_LON=" << pS->gps_longitude
								<< "\tALT=" << pS->altitude << "\tGPS_ALT=" << pS->gps_altitude * 3.2808399 << "\tRADAR_ALT=" << pS->radar_altitude << "\tGS=" << pS->GS << "\tTAS=" << pS->TAS << "\tIAS=" << pS->IAS 
								<< "\tDME\\GPS_DIST=" << pS->DME_GPS_dist << "\tBEARING=" << pS->bearing << "\tDME\\GPS_SPEED=" << pS->DME_GPS_speed << "\tWP_ETE=" << pS->waypoint_ETE << "\tWP_ID=" << pS->waypoint_id << "\n";

							myfile.close();
						}
					}
					break;
				}

				default:
				{
					cout << "Error" << endl;	//Debug output
					break;
				}
			}
			break;
		}

		case SIMCONNECT_RECV_ID_QUIT:
		{
			quit = 1;
			break;
		}

		default:
		{
			//printf("\nRecieved: %d",pData->dwID); //Debug output
			break;
		}
	}
}

void GetData()
{
	HRESULT hr;
	SIMCONNECT_DATA_WAYPOINT wp[6];

	if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Request Heading", NULL, 0, 0, 0)))

	{
		cout << "Connected to Flight Simulator!" << endl;
		// Set up the data definition, but do not yet do anything with it
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "Title", NULL, SIMCONNECT_DATATYPE_STRING256);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATC ID", NULL, SIMCONNECT_DATATYPE_STRING256);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATC AIRLINE", NULL, SIMCONNECT_DATATYPE_STRING256);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "ATC FLIGHT NUMBER", NULL, SIMCONNECT_DATATYPE_STRING256);

		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "HEADING INDICATOR", "radians", SIMCONNECT_DATATYPE_FLOAT64, 0.0078539);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "Plane Altitude", "feet", SIMCONNECT_DATATYPE_FLOAT64, 0.5);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS POSITION ALT", "meters", SIMCONNECT_DATATYPE_FLOAT64, 0.5);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "RADIO HEIGHT", "feet", SIMCONNECT_DATATYPE_FLOAT64, 0.5);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "Plane Latitude", "degrees", SIMCONNECT_DATATYPE_FLOAT64, 0.001);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS POSITION LAT", "degrees", SIMCONNECT_DATATYPE_FLOAT64, 0.001);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "Plane Longitude", "degrees", SIMCONNECT_DATATYPE_FLOAT64, 0.001);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS POSITION LON", "degrees", SIMCONNECT_DATATYPE_FLOAT64, 0.001);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS GROUND SPEED", "meters per second", SIMCONNECT_DATATYPE_FLOAT64, 0.5);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED TRUE", "knots", SIMCONNECT_DATATYPE_FLOAT64, 0.5);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED INDICATED", "knots", SIMCONNECT_DATATYPE_FLOAT64, 0.5);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "HSI DISTANCE", "nautical miles", SIMCONNECT_DATATYPE_FLOAT64, 0.01);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "HSI BEARING", "degrees", SIMCONNECT_DATATYPE_FLOAT64, 0.01);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "HSI SPEED", "knots", SIMCONNECT_DATATYPE_FLOAT64, 0.01);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "TRANSPONDER CODE:1", "BCO16", SIMCONNECT_DATATYPE_FLOAT64, 0.9);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS WP ETE", "seconds", SIMCONNECT_DATATYPE_FLOAT64);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "GPS WP NEXT ID", NULL, SIMCONNECT_DATATYPE_STRING256);
		//hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AI CURRENT WAYPOINT", "number", SIMCONNECT_DATATYPE_FLOAT64, 0.0);
		hr = SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_WAYPOINT, "AI Waypoint List", "number", SIMCONNECT_DATATYPE_WAYPOINT);
		//Request an event when simulation starts
		hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_START, "SimStart");		// triggered event when sim is loaded
		hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_STOP, "SimStop");			// triggered event when sim is in main menu/quited/or in ESC menu

		while (quit == 0)
		{
			SimConnect_CallDispatch(hSimConnect, MyDispatchProcRD, NULL);
			Sleep(1); //Sleep for 1 mSec
		}
		hr = SimConnect_Close(hSimConnect);
		cout << "Sim successfully closed!" << endl;	//Debug output	print when FSX is closed
	}
}





fsx_export::fsx_export(void)
{
}


fsx_export::~fsx_export(void)
{
}

void fsx_export::DoSetup(QThread & fsxThread)
{
	connect(&fsxThread, SIGNAL(started()), this, SLOT(doWork()));
}


void fsx_export::doWork()
{
	emit slot_started();
	GetData();
}