#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	cam.setup(320, 240);

	imitate(previous, cam);
	imitate(diff, cam);
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();
	if (cam.isFrameNew()) {
		absdiff(previous, cam, diff);
		diff.update();

		copy(cam, previous);

		diffmean = mean(toCv(diff)); 

		diffmean += Scalar(50); 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	cam.draw(0,0);
	diff.draw(320, 0);
}

//--------------------------------------------------------------
/*void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}*/
