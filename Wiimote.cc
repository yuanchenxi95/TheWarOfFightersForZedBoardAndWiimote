#include "Wiimote.h"

Wiimote::Wiimote() {
    // Open Wiimote event file
    fd = open("/dev/input/event2", O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
    }
}

Wiimote::~Wiimote() {
    // Close Wiimote event file
    close(fd);
}

int Wiimote::getCode() {
	return this->code;

}

int Wiimote::getValue() {
	return this->value;
}

int Wiimote::setValue(int value) {
	this->value = value;
}

int Wiimote::setCode(int code) {
	this->code = code;
}

void Wiimote::run() {
    
    
        // Read a packet of 32 bytes from Wiimote
        char buffer[32];

	int flag = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag | O_NONBLOCK);
         read(fd, buffer, 32);
        // Extract code (byte 10) and value (byte 12) from packet
	this->code = buffer[10];
        this->value = buffer[12];
        // Print them
       std::cout << "Code = " << code << ", value = " << value << '\n';
    
}
