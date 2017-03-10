import processing.serial.*;
Serial port;

float centroid;
int sendCentroid;

// import TSPS
import tsps.*;
TSPS tspsReceiver;

void setup(){
  size(1024,768);

  //all you need to do to start TSPS
  tspsReceiver= new TSPS(this, 12000);
 // println(Serial.list());
  port = new Serial(this,Serial.list()[4],9600);
};

void draw(){
  background(0);
  
  // get array of people
  TSPSPerson[] people = tspsReceiver.getPeopleArray();
  
  
  // loop through people
  for (int i=0; i<people.length; i++){
    // there is also people[i].centroid.y*height
      centroid = people[i].centroid.x*width;
      ellipse(centroid,300,20,20);
      sendCentroid = int((map(centroid,0,1000,0,50)));
      println(sendCentroid);
      port.write(sendCentroid);
  };
};