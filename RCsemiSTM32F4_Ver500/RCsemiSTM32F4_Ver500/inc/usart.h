/*
 * usart.h
 *
 *  Created on: 2017/04/19
 *      Author: mugi111
 */

#ifndef USART_H_
#define USART_H_

#define CTRL_RECV_TIMEOUT_MS	200	// S��y�̊�
#define BT_BAUDRATE	9600

#define RECV_RINGBUFF_SIZE 16

typedef struct
{
	volatile int recvPtr_in;
	volatile int recvPtr_out;

	uint8_t buff[RECV_RINGBUFF_SIZE];
}ringBuffer_t;

namespace RCsemi{

class usart{
	static ringBuffer_t ctrl_buffer;
public:
	usart(int baud);

	int ctrl_RecvByte(void);
	int	ctrl_RecvString(char *buf, int max);
	void ctrl_SendByte(uint8_t byte);
	void ctrl_SendString(char *str);
	void USART6_IRQHandler(void);
};

}



#endif /* USART_H_ */
