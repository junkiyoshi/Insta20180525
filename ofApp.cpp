#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.25);

	int aggregation_size = 720;
	int box_size = 72;
	ofColor box_color;
	for (int x = -aggregation_size / 2; x <= aggregation_size / 2; x += box_size) {

		for (int y = -aggregation_size / 2; y <= aggregation_size / 2; y += box_size) {

			for (int z = -aggregation_size / 2; z <= aggregation_size / 2; z += box_size) {

				float noise_value = ofNoise(x * 0.004, y * 0.004, z * 0.004, ofGetFrameNum() * 0.005);
				noise_value = noise_value > 0.5 ? 1 : noise_value;
				
				box_color.setHsb(ofRandom(255), 225, 225);
				ofSetColor(box_color);

				ofDrawBox(ofPoint(x, y, z), box_size * noise_value);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}