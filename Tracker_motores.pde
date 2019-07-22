//The blob detection part of the code was done using the existing code shared by The Coding Train on youtube.

import processing.serial.*;
import processing.video.*;

Serial myPort;

int counter1=0;
int counter2=0;
int counter3=0;
int counter4=0;
int counter5=0;


Capture video;

color trackColor; 
float threshold = 25;
float distThreshold = 15;


ArrayList<Blob> blobs = new ArrayList<Blob>();

void setup() {
  size(640, 480);
  String[] cameras = Capture.list();
  printArray(cameras);
  video = new Capture(this, 640, 480);
  video.start();
  trackColor = color(255, 0, 0);

  myPort = new Serial(this, "COM4", 9600);
}

void captureEvent(Capture video) {
  video.read();
}

void keyPressed() 
{
  if (key == 'a') { //a aumenta  distancia tolerancia a union de manchas
    distThreshold+=5;
  } else if (key == 'z') {//z disminuye distancia tolerancia a union de manchas
    distThreshold-=5;
  }
  if (key == 's') {
    threshold+=5; //s
  } else if (key == 'x') {
    threshold-=5; //x
  }

  println(distThreshold);
}



void draw() 
{
  video.loadPixels();
  image(video, 0, 0);

  blobs.clear();
  counter1=0;
  counter2=0;
  counter3=0;
  counter4=0;
  counter5=0;


  // Begin loop to walk through every pixel
  for (int x = 0; x < video.width; x++ ) {
    for (int y = 0; y < video.height; y++ ) {
      int loc = x + y * video.width;
      // What is current color
      color currentColor = video.pixels[loc];
      float r1 = red(currentColor);
      float g1 = green(currentColor);
      float b1 = blue(currentColor);
      float r2 = red(trackColor);
      float g2 = green(trackColor);
      float b2 = blue(trackColor);

      float d = distSq(r1, g1, b1, r2, g2, b2); 

      if (d < threshold*threshold) {

        boolean found = false;
        for (Blob b : blobs) {
          if (b.isNear(x, y)) {
            b.add(x, y);
            found = true;
            break;
          }
        }

        if (!found) {
          Blob b = new Blob(x, y);
          blobs.add(b);
        }
      }
    }
  }

  for (Blob b : blobs) {
    if (b.size() > 500 ) {
      b.show();// hace el cuadrado blanco y actualiza los counters(ver blob )
    }
  }

  //Serial send to ardruino counter 1,2,3,4,5
  println("El numero de manchas en la seccion 1 es: ");
  println(counter1);
  if(counter1==0) {myPort.write('0');}
  if(counter1>0) {myPort.write('1');}
  
  println("El numero de manchas en la seccion 2 es: ");
  println(counter2);
  if(counter2==0) {myPort.write('2');}
  if(counter2>0) {myPort.write('3');}
  
  println("El numero de manchas en la seccion 3 es: ");
  println(counter3);
  if(counter3==0) {myPort.write('4');}
  if(counter3>0) {myPort.write('5');}
  
  println("El numero de manchas en la seccion 4 es: ");
  println(counter4);
  if(counter4==0) {myPort.write('6');}
  if(counter4>0) {myPort.write('7');}
  
  println("El numero de manchas en la seccion 5 es: ");
  println(counter5);
  if(counter5==0) {myPort.write('8');}
  if(counter5>0) {myPort.write('9');}


  textAlign(RIGHT);
  fill(0);
  text("distance threshold: " + distThreshold, width-10, 25);
  text("color threshold: " + threshold, width-10, 50);
}


// Custom distance functions w/ no square root for optimization
float distSq(float x1, float y1, float x2, float y2)
{
  float d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  return d;
}


float distSq(float x1, float y1, float z1, float x2, float y2, float z2) {
  float d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) +(z2-z1)*(z2-z1);
  return d;
}

void mousePressed() 
{
  // Save color where the mouse is clicked in trackColor variable
  int loc = mouseX + mouseY*video.width;
  trackColor = video.pixels[loc];
}