#ifndef __DIGITALIO__
#define __DIGITALIO__

#define DIO_MODE_INPUT GPIO_MODE_INPUT
#define DIO_MODE_OUTPUT GPIO_MODE_OUTPUT_PP

namespace RCsemi{

class digitalIO{
	unsigned int m_port;
	unsigned int m_pin;
	unsigned int m_mode;
public:
	digitalIO(unsigned int port, unsigned int pin, unsigned long mode);

	void OutputPin(unsigned int status);
	void TogglePin();
	int CheckPin();
};

} //namespace RCsemi


#endif //__DIGITALIO__

