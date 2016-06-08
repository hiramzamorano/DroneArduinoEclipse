/*
 * CFrontSensor.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: vinu
 */

#include "CFrontSensor.h"
void isort(int *a, int n);
int mode(int *x,int n);

CFrontSensor::CFrontSensor()
{
	m_PWpinNumber=0;
	m_TRIGpinNumber=0;

}
void CFrontSensor::Pin_init(unsigned char PWpinnum,unsigned char TRIGGpinnum) {
	// TODO Auto-generated constructor stub
	pinMode(PWpinnum, INPUT);
	pinMode(TRIGGpinnum,OUTPUT);
	m_PWpinNumber=PWpinnum;
	m_TRIGpinNumber=TRIGGpinnum;

}

CFrontSensor::~CFrontSensor() {
	// TODO Auto-generated destructor stub
}

int CFrontSensor:: read_sensor(){

	int pulseWidth,distanceinCM;
	digitalWrite(m_TRIGpinNumber,HIGH);
	pulseWidth = pulseIn(m_PWpinNumber, HIGH);
	distanceinCM = pulseWidth/58;
	digitalWrite(m_TRIGpinNumber,LOW);

	return distanceinCM;
}

int CFrontSensor::read_sensor_Filtered(unsigned char arraysize, unsigned char read_delay)
{
	//declare an array to store the samples. not necessary to zero the array values here, it just makes the code clearer
	int rangevalue[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0};
		int modE;

	for(int i = 0; i < arraysize; i++)
	{
		rangevalue[i] = read_sensor();
		delay(read_delay);
	}

	isort(rangevalue,arraysize);

	modE = mode(rangevalue,arraysize);
	//Serial.print("The mode/median is: ");
	return modE;
}

void isort(int *a, int n)
//  *a is an array pointer function
{
	for (int i = 1; i < n; ++i)   {
		int j = a[i];     int k;
		for (k = i - 1; (k >= 0) && (j < a[k]); k--)
		{
			a[k + 1] = a[k];
		}
		a[k + 1] = j;
	}
}

//Sorting function


//Mode function, returning the mode or median.
int mode(int *array,int size){
	int number = array[0];
	int mode = number;
	int count = 1;
	int countMode = 1;

	for (int i=1; i<size; i++)
	{
	      if (array[i] == number)
	      { // count occurrences of the current number
	         countMode++;
	      }
	      else
	      { // now this is a different number
	            if (count > countMode)
	            {
	                  countMode = count; // mode is the biggest ocurrences
	                  mode = number;
	            }
	           count = 1; // reset count for the new number
	           number = array[i];
	  }
	}

	return mode;
}


