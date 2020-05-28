#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0); // white background
    
    /*
    pos1.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    pos2.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    pos3.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    
    vel1.set(ofRandom(-5,5), ofRandom(-5,5));
    vel2.set(ofRandom(-5,5), ofRandom(-5,5));
    vel3.set(ofRandom(-5,5), ofRandom(-5,5));
     */
 
    
    //arrays must be initialized before using them
    
    //initialize array pos
    for(int i=0; i<NUM; i++){
        pos[i].set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }
    
    //initialize array vel
     for(int i=0; i<NUM; i++){
        vel[i].set(ofRandom(-3,3), ofRandom(-3,3));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    /*
    pos1 += vel1; 
    pos2 += vel2;
    pos3 += vel3;
    
    //boundary
    if(pos1.x > ofGetWidth())pos1.x = 0;
    if(pos1.x < 0)pos1.x = ofGetWidth();
    if(pos1.y > ofGetHeight()) pos1.y = 0;
    if(pos1.y < 0) pos1.y = ofGetHeight();
    
    if(pos2.x > ofGetWidth())pos2.x = 0;
    if(pos2.x < 0)pos2.x = ofGetWidth();
    if(pos2.y > ofGetHeight()) pos2.y = 0;
    if(pos2.y < 0) pos2.y = ofGetHeight();
    
    if(pos3.x > ofGetWidth())pos3.x = 0;
    if(pos3.x < 0)pos3.x = ofGetWidth();
    if(pos3.y > ofGetHeight()) pos3.y = 0;
    if(pos3.y < 0) pos3.y = ofGetHeight();
     */
    
    //update posiitons
    for(int i=0; i<NUM; i++){
        //pos[i] += vel[i];
        pos[i].x += vel[i].x + ofRandom(-1,1);
        pos[i].y += vel[i].y + ofRandom(-1,1);
    }
    
    // boundary condition
    for(int i=0; i<NUM; i++){
        if(pos[i].x < 0) pos[i].x = ofGetWidth();
        if(pos[i].x > ofGetWidth()) pos[i].x = 0;
        if(pos[i].y < 0) pos[i].y = ofGetHeight();
        if(pos[i].y > ofGetHeight()) pos[i].y = 0;
    }
    
    //particleSize = 10;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255), 100);  //black perticle
    
    /*
    ofDrawCircle(pos1, 10);
    ofDrawCircle(pos2, 10);
    ofDrawCircle(pos3, 10);
     */
    
    
    for(int i=0; i<NUM; i++){
        ofDrawCircle(pos[i], particleSize);
    }

    
    for(int i=0; i<NUM; i++){
        ofVec2f tmp = pos[i];
        
        for(int j=0; j<NUM; j++){
            ofVec2f other = pos[j];
            
            if(tmp.distance(other) < ofRandom(10,100)){
                ofDrawLine(tmp, other);
            }
        }
    }
    
    /*
    for(int i=0; i<NUM; i++){
        ofDrawCone(pos[i].x, pos[i].y, particleSize, particleSize);
        ofDrawRectangle(pos[i].x, pos[i].y, particleSize, particleSize);
    }
    */
    
    //which means,
    //ofdrawcircle(pos[0], 5);
    //ofdrawcircle(pos[1], 5);
    //ofdrawcircle(pos[2], 5);
    //  .....
    //ofdrawcircle(pos[99], 5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's' && particleSize < 50) particleSize ++;
    if(key == 'd' && particleSize > 1) particleSize --;
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

}
