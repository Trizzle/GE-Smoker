//
//  uiManager.cpp
//  GE_smoker-screen1
//
//  Created by Jack Kalish on 2/24/15.
//
//

#include "uiManager.h"

uiManager::uiManager(){
    ofSetVerticalSync(true);
    
    ofBackground(255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    //define some vars
    w = 1920;
    h = 1080;
    
    //allocate image objects
    screenFbo.allocate(w, h);
    screenImage.allocate(w, h, OF_IMAGE_COLOR);
    
    //load all fonts to be used
    float fontScale = .75;
    fontGE170B.loadFont("GEInsBol", 170*fontScale);
    fontGE85B.loadFont("GEInsBol", 85*fontScale);
    fontGE54B.loadFont("GEInsBol", 54*fontScale);
    
    //define colors
    red.setHex(0xd1202a);
    blue.setHex(0x0c6bbd);
    
    isFullScreen = true;
}

void uiManager::update(){
    //read FBO to image
    screenFbo.readToPixels(screenImage);
    //scale the screen image based on the screen size
    int newHeight = (ofGetWidth()*h)/w;
    screenImage.resize(ofGetWidth(), newHeight);
}

void uiManager::draw(){
    //don't forget to reset the color to white tho!
    ofSetColor(255);
    screenImage.draw(0,0);
}

void uiManager::keyPressed(int key){
    switch(key){
        case 'f':
            isFullScreen = ! isFullScreen;
            ofSetFullscreen(isFullScreen);
            break;
    }
}