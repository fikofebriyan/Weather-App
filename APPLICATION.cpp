
//------------------------------------------------------------------------------------------------
#include "APPLICATION.h"

//------------------------------------------------------------------------------------------------
void Application::DisplayMenu()
{
    cout << endl;
    cout << "==============Menu Options=============="<< endl;
    cout << "1. The average wind speed and average ambient air temperature for a specified month and year" << endl;
    cout << "2. Average wind speed and average ambient air temperature for each month of a specified year" << endl;
    cout << "3. Total solar radiation in kWh/m2 for each month of a specified year (Above 100 kWh/m2) " << endl;
    cout << "4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year"<< endl;
    cout << "5. Highest Solar Radiation and Time for given Date " << endl;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << "Enter Choice" << endl;
}


//------------------------------------------------------------------------------------------------
void Application::UserInput()
{

    // to read file first before performing the program
    ReadFile();

    // display menu for user to choose
    DisplayMenu();

    int choice;

    do
    {
         cin >> choice;
         switch(choice)
         {
            case 1:
            cout << "Please Enter month: " << endl;
            cin >> month;
            cout << endl;

            cout << "Please Enter year: "<< endl;
            cin >> year;
            cout << endl;
            choice1();
            DisplayMenu();
            break;

            case 2:
            cout << "Please Enter year: " << endl;
            cin >> year;
            cout << endl;
            choice2();
            DisplayMenu();
            break;

            case 3:
            cout << "Please Enter year: " << endl;
            cin >> year;
            cout << endl;
            choice3();
            DisplayMenu();
            break;

            case 4:
            cout << "Please Enter year: " << endl;
            cin >> year;
            cout << endl;
            choice4();
            DisplayMenu();
            break;

            case 5:
            cout << "Please Enter Day: " << endl;
            cin >> day;
            cout << endl;

            cout <<"Please Enter Month: " << endl;
            cin >> month;
            cout << endl;

            cout << "Please Enter year: " << endl;
            cin >> year;
            cout << endl;

            choice5();
            DisplayMenu();
            break;

            case 6:
            cout << "Program End" << endl;
            break;

            default:
            cout << "Choice not found" << endl;
            break;
         }
    }
   while(choice > 0 && choice < 6);

}

//------------------------------------------------------------------------------------------------
void Application::ReadFile()
{

    // initialise objects for date, time and windlog
    string dd, mm, yyyy;
    string hour, minute;
    string speed, SolarR,AirTemp ;

    // to be use in getline to skip line
    string row;

    // use to convert speed, solar, air temperature
    float convertSpeed, convertSolarR, convertAirTemp;

    float TotalWindSpeed = 0;
    float TotalSolarR = 0;
    float TotalAirTemp = 0;

    ifstream CSVFile;
    ifstream TextFile;
    string csvfiles, filename ;

    // open data folder contains text file
    TextFile.open("data/met_index.txt");

    // store month and year into map
    for (int i = 2006; i <= 2016; i++)
    {
        for (int j = 1; j<=12; j++)
        {
            vector < Windlog> WV;
            MapW[i][j] = WV;
        }
    }

    int speedCounter = 0;
    int AirTempCounter = 0;

    //read textfile
    while (!TextFile.eof())
    {
        getline(TextFile, filename,'\n');

        // initialise csv file name to csvfiles
        csvfiles = "data/" +filename;

        // to access string data
        CSVFile.open(csvfiles.c_str());

        // to see if we can open each csv file
        if (!CSVFile.is_open())
        {
            cout << "CSV File not found" << endl;
        }
        else
        {
            //read csv file that get speed, radiation, temp, date ,time
           while(!CSVFile.eof())
           {
	            // get date and time
		        getline(CSVFile, dd, '/');
		        getline(CSVFile, mm, '/');
		        getline(CSVFile, yyyy, ' ');
		        getline(CSVFile, hour, ':');
		        getline(CSVFile, minute, ',');

                // skip to speed column
                for(int i = 0; i < 10; i++)
                {
                    getline(CSVFile, speed,',');
                }

                // get solar radiation
                getline(CSVFile, SolarR,',');

                // ignore the next 5 columns
                for (int i = 0; i < 5; i++)
                {
                    CSVFile.ignore(30,',');
                }

                // get air temp
			    getline(CSVFile, AirTemp,'\n');

		        //  convert string to integer
		        int days = atoi(dd.c_str());
		        int months = atoi(mm.c_str());
		        int years = atoi(yyyy.c_str());
		        int hours = atoi(hour.c_str());
		        int minutes = atoi(minute.c_str());

		        // convert string to  float
		        convertSpeed = atof(speed.c_str());
                convertSolarR = atof(SolarR.c_str());
                convertAirTemp = atof(AirTemp.c_str());

                // create needed for choice 5
                // declare windlogtype struct object
                WindLogType windL;

                // set day, month, year into setDate
                windL.d.setDate(day,month,year);

                if(windL.d.getDay() == days && windL.d.getMonth() == months && windL.d.getYear() == years)
                {
                    windL.TimeStruct.setTime(hours,minutes);
                    windL.radiation = convertSolarR;

                    // insert date
                    BST.insertNode(days);
                    BST.insertNode(months);

                    if(convertSolarR > 100)
                    {
                        // push windlog into vector
                        windlog.push_back(windL);

                        //insert into BST
                        BST.insertNode(convertSolarR);
                        BST.insertNode(convertAirTemp);
                        BST.insertNode(convertSpeed);
                    }
                }

                // get another row
                getline(CSVFile,row,'\n');

                // function below to calculate speed, solar, temperature
                // for choice 1-4
                if(dateApp.getYear() == years && dateApp.getMonth() == months )
                {
                        speedCounter++;
                        TotalWindSpeed += convertSpeed * 3.6;
                        AverageSpeed = TotalWindSpeed/speedCounter;

                        if(convertSolarR >= 100)
                        {
                            TotalSolarR = TotalSolarR + convertSolarR;
                            radiation = ( (TotalSolarR/6) /1000 ) ;
                        }
                        AirTempCounter++;
                        TotalAirTemp = TotalAirTemp + convertAirTemp;
                        AverageAirTemp = TotalAirTemp/AirTempCounter;
                }
            }
        }
        CSVFile.close();
    }
    TextFile.close();
}

//------------------------------------------------------------------------------------------------
void Application::choice1()
{
    cout << "1. The average wind speed and average ambient air temperature for a specified month and year" << endl;
    cout<< endl;

    // to read file first before performing the program
    ReadFile();

    dateApp.setMonth(month);
    dateApp.setYear(year);

    // read file function has already calculate the average
    WindL.SetWindSpeed(AverageSpeed);
    WindL.SetAirTemperature(AverageAirTemp);

    if(AverageSpeed > 0 && AverageAirTemp > 0)
    {
        cout << dateApp.StringMonth(month) << " "<< dateApp.getYear() <<": "<< WindL.GetWindSpeed() << " km/h, " << WindL.GetTemperature() << " degree C"<<endl;
    }
    else
    {
        cout << dateApp.StringMonth(month) << " "<< dateApp.getYear() <<": no record"<<endl;
    }

    // clear vector so other choice can perform
    windlog.clear();
    // delete tree so other choice can perform
    BST.DeleteTree();
}

//------------------------------------------------------------------------------------------------
void Application:: choice2()
{
    cout << "2. Average wind speed and average ambient air temperature for each month of a specified year" << endl;
    cout<< endl;

    dateApp.setYear(year);

    for(int i=1; i<=12; i++)
    {
        // to read file first before performing the program
       ReadFile();
       dateApp.setMonth(i);

        // read file function has already calculate the average
       WindL.SetWindSpeed(AverageSpeed);
       WindL.SetAirTemperature(AverageAirTemp);

       if(AverageSpeed > 0 && AverageAirTemp >0)
       {
           cout << dateApp.StringMonth(i) <<": "<< WindL.GetWindSpeed() << " km/h, " << WindL.GetTemperature() << " degree C"<<endl;
       }
       else
       {
           cout << dateApp.StringMonth(i) <<": no record"<<endl;
       }

    }
    // clear vector so other choice can perform
    windlog.clear();
    // delete tree so other choice can perform
    BST.DeleteTree();
}

//------------------------------------------------------------------------------------------------
void Application::choice3()
{
    cout << "3. Total solar radiation in kWh/m2 for each month of a specified year  " << endl;
    cout<< endl;

    dateApp.setYear(year);

    for(int i=1; i<=12; i++)
    {
        // to read file first before performing the program
       ReadFile();
       dateApp.setMonth(i);

       WindL.SetSolarRadiation(radiation);
       if(radiation > 0)
       {
           cout << dateApp.StringMonth(i) << ": "<< WindL.GetRadiation() << " kWh/m^2"<<endl;
        }
       else
       {
           cout << dateApp.StringMonth(i) <<": no record"<<endl;
        }

    }
     // clear vector so other choice can perform
    windlog.clear();
    // delete tree so other choice can perform
    BST.DeleteTree();
}

//------------------------------------------------------------------------------------------------
void Application::choice4()
{
    cout << "4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year"<< endl;
    cout << endl;

    ofstream outFile("WindSolarTemp.csv");

    cout << "Printed into WindSolarTemp.csv of " << year ;
    dateApp.setYear(year);

    outFile << year << endl;
    outFile << "Month " << ", "<<"Speed "<<", "<< "Solar R "<<", "<< "Temperature "<<endl;

    for(int i=1; i<=12; i++)
    {
       // to read file first before performing the program
       ReadFile();
       dateApp.setMonth(i);

       WindL.SetWindSpeed(AverageSpeed);
       WindL.SetAirTemperature(AverageAirTemp);
       WindL.SetSolarRadiation(radiation);

       outFile << dateApp.StringMonth(i) <<","<< WindL.GetWindSpeed()
       << "," << WindL.GetRadiation() << "," << WindL.GetTemperature() <<endl;
    }
   // clear vector so other choice can perform
    windlog.clear();
    // delete tree so other choice can perform
    BST.DeleteTree();
}

//------------------------------------------------------------------------------------------------
void Application::choice5()
{
    cout << "5. Highest Solar Radiation and Time for given Date " << endl;
    cout<< endl;

    // to get highest  solar for choice 5
    float MaximumSolarR = 0;

    // declare map of string and float
    map<string, float> Maps;

    WindLogType WL;
    WL.d.setDate(day,month,year);

    // to read file first before performing the program
     ReadFile();

    // ensure maximum radiation is equals to bst highest node
    for(int i=0; i<windlog.size();i++)
    {
        MaximumSolarR = BST.MaximumValue();
    }
    cout << "Date: " << WL.d.getDay() << " " << WL.d.StringMonth(month) << " " << WL.d.getYear() <<endl;

    if(MaximumSolarR > 100)
    {
        // store into map
        Maps.insert( pair<string, float>("Highest Solar Radiation: ", MaximumSolarR ) );

        //create iterator of map
        map<string, float>::iterator itr;

        // print map
        for(itr = Maps.begin(); itr != Maps.end(); itr++)
        {
            cout << itr->first << itr->second << " W/m^2"<< endl;
        }
        cout << endl;

        // print time
        for(int i=0; i < windlog.size();i++)
        {
            if(windlog[i].radiation == MaximumSolarR)
            {
                cout << windlog[i].TimeStruct << endl;
            }
        }
    }
    else
    {
        cout << "Data not found "<<endl;
    }

    Maps.clear();

    // clear vector so other choice can perform
    windlog.clear();
    // delete tree so other choice can perform
    BST.DeleteTree();
}
