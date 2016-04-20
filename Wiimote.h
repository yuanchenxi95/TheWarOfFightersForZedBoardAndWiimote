//
//  Wiimote.hpp
//  Lab5
//
//  Created by Chenxi Yuan on 2016/2/11.
//  Copyright © 2016. Chenxi Yuan. All rights reserved.
//

#ifndef Wiimote_h
#define Wiimote_h

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


class Wiimote {
public:
    Wiimote();
    ~Wiimote();
    
    void run();
	int getCode();
	int getValue();
	int setValue(int value);
	int setCode(int code);    
private:
    int fd;
	int code;
	int value;
};


#endif /* Wiimote_hpp */

