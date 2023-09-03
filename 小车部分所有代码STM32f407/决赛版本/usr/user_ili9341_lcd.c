#include "user_ili9341_lcd.h"
#include "ascii.h"	


#define DEBUG_DELAY()   sw_delay_ms(1)

/**************************************************************************************
 * ��  �� : ��ʼ������TFTLCD��IO
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
 void LCD_ili9341_DrawPicture(u16 StartX,u16 StartY,u16 Xend,u16 Yend,const unsigned char *pic)
{
    static   u16 i=0,j=0;
//		extern int play;

u16 *bitmap = (u16 *)pic;
    
    
    LCD_OpenWindow(StartX,StartY,Xend,Yend);
		LCD_ILI9341_CMD(0x2c);	         /* д���� */
		
    for(i=StartY;i<Yend;i++)
    {

            for(j=StartX;j<Xend;j++)
{
//LCD_WR_Data(*bitmap++); 

	LCD_WR_Data(*bitmap++);

	//LCD_SetPoint(j ,i ,*bitmap++);
}        
    }
    
}

 void Lcd_GramScan( uint16_t option )
{	
	switch(option)
	{
		case 1:
		{/* ���Ͻ�->���½�      ��ʾ��Ӣ��ʱ�õ�������ģʽ */
			LCD_ILI9341_CMD(0x36); 
			LCD_ILI9341_Parameter(0xC8);   
			LCD_ILI9341_CMD(0X2A); 
			LCD_ILI9341_Parameter(0x00);	/* x start */	
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);  /* x end */	
			LCD_ILI9341_Parameter(0xEF);

			LCD_ILI9341_CMD(0X2B); 
			LCD_ILI9341_Parameter(0x00);	/* y start */  
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x01);	/* y end */   
			LCD_ILI9341_Parameter(0x3F);
					
		}break;
		case 2:
		{/* ���½�->���Ͻ�      ��ʾ����ͷͼ��ʱ�õ�������ģʽ */	
			LCD_ILI9341_CMD(0x36); 
			LCD_ILI9341_Parameter(0x68);	
			LCD_ILI9341_CMD(0X2A); 
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x01);
			LCD_ILI9341_Parameter(0x3F);	

			LCD_ILI9341_CMD(0X2B); 
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0xEF);			
		}break;
		case 3:
		{/* ���½�->���Ͻ�      ��ʾBMPͼƬʱ�õ�������ģʽ */
			LCD_ILI9341_CMD(0x36); 
			LCD_ILI9341_Parameter(0x28);	
			LCD_ILI9341_CMD(0X2A); 
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x01);
			LCD_ILI9341_Parameter(0x3F);	

			LCD_ILI9341_CMD(0X2B); 
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0x00);
			LCD_ILI9341_Parameter(0xEF);			
		}break;
	}
}
void sw_delay_ms(uint16_t ms){
	uint32_t i;
	
		for(i=0;i<10000;i=i+1);
		
	
	
}
		
//void LCD_GPIO_Config(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    
//	
//    /* ʹ��FSMCʱ��*/
//	
//	     
//	  RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FMC, ENABLE);
//    
//    
//    /* ʹ��FSMC��Ӧ��Ӧ�ܽ�ʱ��*/
//		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE , ENABLE);
//    
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
//    
//    /* ����LCD������ƹܽ�*/
//    GPIO_InitStructure.GPIO_Pin = LCD_BL_PIN;		
//    GPIO_Init(LCD_BL_PORT, &GPIO_InitStructure);
//    
//    /* ����LCD��λ���ƹܽ�*/
//    GPIO_InitStructure.GPIO_Pin = LCD_RST_PIN ; 	 
//    GPIO_Init(LCD_RST_PORT, &GPIO_InitStructure);  		   
//    
//    /* ����FSMC���Ӧ��������,FSMC-D0~D15: PD 14 15 0 1,PE 7 8 9 10 11 12 13 14 15,PD 8 9 10*/	
//    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
//    GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF;
//    
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | 
//                                  GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
//                                  GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
//                                  GPIO_Pin_15;
//    GPIO_Init(GPIOE, &GPIO_InitStructure); 
//    
//		/* ����FSMC���Ӧ�Ŀ�����
//		 * PD4-FSMC_NOE   :LCD-RD
//		 * PD5-FSMC_NWE   :LCD-WR
//		 * PG12-FSMC_NE1  :LCD-CS
//		 * PG0-FSMC_A16   :LCD-DC
//		*/
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; 
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//    
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; 
//    GPIO_Init(GPIOD, &GPIO_InitStructure);  
//		
//		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
//    GPIO_Init(GPIOD, &GPIO_InitStructure); 
//    
//    /* ������ */
//		GPIO_ResetBits(LCD_BL_PORT, LCD_BL_PIN);  
//}

/**************************************************************************************
 * ��  �� : TFTLCD  FSMC ģʽ����
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
//void LCD_FSMC_Config(void)
//{
//		FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
//    FSMC_NORSRAMTimingInitTypeDef  p; 
//    
//    
//    p.FSMC_AddressSetupTime = 0x02;	 //��ַ����ʱ��
//    p.FSMC_AddressHoldTime = 0x00;	 //��ַ����ʱ��
//    p.FSMC_DataSetupTime = 0x05;		 //���ݽ���ʱ��
//    p.FSMC_BusTurnAroundDuration = 0x00;
//    p.FSMC_CLKDivision = 0x00;
//    p.FSMC_DataLatency = 0x00;
//    p.FSMC_AccessMode = FSMC_AccessMode_B;	 // һ��ʹ��ģʽB������LCD
//    
//    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM4;
//    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
//    //FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
//		FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
//    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
//    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
//    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
//    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
//    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
//    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
//    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
//    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
//    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
//    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
//    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;  
//    
//    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 
//    
//    /* ʹ�� FSMC Bank1_SRAM Bank */
//    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM4, ENABLE);  
//}

/**************************************************************************************
 * ��  �� : TFTLCD ��λ
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
void LCD_Rst(void)
{			
		HAL_GPIO_WritePin(LCD_RST_PORT,LCD_RST_PIN , GPIO_PIN_RESET);
			 //�͵�ƽ��λ
    sw_delay_ms(1); 					   
    HAL_GPIO_WritePin(LCD_RST_PORT,LCD_RST_PIN , GPIO_PIN_SET);		 	 
    sw_delay_ms(1);
		HAL_GPIO_WritePin(LCD_BL_PORT,LCD_BL_PIN , GPIO_PIN_RESET);
}

/**************************************************************************************
 * ��  �� : TFTLCD ��ʼ���Ĵ���
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
void LCD_REG_Config(void)
{
  LCD_ILI9341_CMD(0x11); 
  sw_delay_ms(120); 
 
  LCD_ILI9341_CMD(0x36);  
  LCD_ILI9341_Parameter(0x00); 

  LCD_ILI9341_CMD(0x3A); 
  LCD_ILI9341_Parameter(0X05); 
 
  LCD_ILI9341_CMD(0xB2);  
  LCD_ILI9341_Parameter(0x0C); 
  LCD_ILI9341_Parameter(0x0C); 
  LCD_ILI9341_Parameter(0x00); 
  LCD_ILI9341_Parameter(0x33);
  LCD_ILI9341_Parameter(0x33);

  LCD_ILI9341_CMD(0xB7);  
  LCD_ILI9341_Parameter(0x35); 

  LCD_ILI9341_CMD(0xBB);  				//vcom
  LCD_ILI9341_Parameter(0x32);    //30

  LCD_ILI9341_CMD(0xC0);  				  //
  LCD_ILI9341_Parameter(0x2C); 

  LCD_ILI9341_CMD(0xC2);  
  LCD_ILI9341_Parameter(0x01); 
 
  LCD_ILI9341_CMD(0xC3);  	   //vrh
  LCD_ILI9341_Parameter(0x10); 	   //17		   0D

  LCD_ILI9341_CMD(0xC4);  			   //vdv
  LCD_ILI9341_Parameter(0x20);	  //20

  LCD_ILI9341_CMD(0xC6);  
  LCD_ILI9341_Parameter(0x0f);     //0f ����������

  LCD_ILI9341_CMD(0xD0);  
  LCD_ILI9341_Parameter(0xA4); 
  LCD_ILI9341_Parameter(0xA1); 
 
  LCD_ILI9341_CMD(0xE0);    //Set Gamma 
  LCD_ILI9341_Parameter(0xd0); 
  LCD_ILI9341_Parameter(0x00); 
  LCD_ILI9341_Parameter(0x02); 
  LCD_ILI9341_Parameter(0x07); 
  LCD_ILI9341_Parameter(0x0a); 
  LCD_ILI9341_Parameter(0x28); 
  LCD_ILI9341_Parameter(0x32); 
  LCD_ILI9341_Parameter(0X44); 
  LCD_ILI9341_Parameter(0x42); 
  LCD_ILI9341_Parameter(0x06); 
  LCD_ILI9341_Parameter(0x0e); 
  LCD_ILI9341_Parameter(0x12); 
  LCD_ILI9341_Parameter(0x17); 
 
  LCD_ILI9341_CMD(0XE1);    //Set Gamma 
  LCD_ILI9341_Parameter(0xd0); 
  LCD_ILI9341_Parameter(0x00); 
  LCD_ILI9341_Parameter(0x02); 
  LCD_ILI9341_Parameter(0x07); 
  LCD_ILI9341_Parameter(0x0a); 
  LCD_ILI9341_Parameter(0x28); 
  LCD_ILI9341_Parameter(0x31); 
  LCD_ILI9341_Parameter(0x54); 
  LCD_ILI9341_Parameter(0x47); 
  LCD_ILI9341_Parameter(0x0e); 
  LCD_ILI9341_Parameter(0x1c); 
  LCD_ILI9341_Parameter(0x17); 
  LCD_ILI9341_Parameter(0x1b); 
  LCD_ILI9341_Parameter(0x1e); 

  LCD_ILI9341_CMD(0x2A); 
  LCD_ILI9341_Parameter(0x00);
  LCD_ILI9341_Parameter(0x00);
  LCD_ILI9341_Parameter(0x00);
  LCD_ILI9341_Parameter(0xef);	

  LCD_ILI9341_CMD(0x2B); 
  LCD_ILI9341_Parameter(0x00);
  LCD_ILI9341_Parameter(0x00);
  LCD_ILI9341_Parameter(0x01);
  LCD_ILI9341_Parameter(0x3f); 

  LCD_ILI9341_CMD(0x29); //display on
  LCD_ILI9341_CMD(0x2c);
}

/**************************************************************************************
 * ��  �� : TFTLCD��ʼ��
 * ��  �� : ��
 * ����ֵ : ��
 **************************************************************************************/
//void LCD_Init(void)
//{
//	LCD_GPIO_Config();
//	LCD_FSMC_Config();
//	
//	LCD_Rst();
//	LCD_REG_Config();
//}


void LCD_Clear(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color)
{
	uint32_t i = 0;
	
	/* column address control set */
	LCD_ILI9341_CMD(0X2A);
	LCD_ILI9341_Parameter( x >> 8 );	 /* �ȸ�8λ��Ȼ���8λ */
	LCD_ILI9341_Parameter( x & 0xff );	         /* column start   */ 
	LCD_ILI9341_Parameter( (x+width-1) >> 8 );   /* column end   */
	LCD_ILI9341_Parameter( (x+width-1) & 0xff );
	
	/* page address control set */	
  LCD_ILI9341_CMD(0X2B); 			     
	LCD_ILI9341_Parameter( y >> 8 );			/* page start   */
	LCD_ILI9341_Parameter( y & 0xff );
	LCD_ILI9341_Parameter( (y+height-1) >> 8);  /* page end     */
	LCD_ILI9341_Parameter( (y+height-1) & 0xff);
	
	/* memory write */
	LCD_ILI9341_CMD(0x2c);	
		
	for( i=0; i < width*height; i++ )
	{
		LCD_WR_Data( color );
	}	
}


void LCD_SetCursor(uint16_t x, uint16_t y)	
{	
	LCD_ILI9341_CMD(0X2A); 				 /* ����X���� */
	LCD_ILI9341_Parameter(x>>8);	 /* �ȸ�8λ��Ȼ���8λ */
	LCD_ILI9341_Parameter(x&0xff);	 /* ������ʼ��ͽ�����*/
	LCD_ILI9341_Parameter(x>>8);
	LCD_ILI9341_Parameter(x&0xff);

    LCD_ILI9341_CMD(0X2B); 			     /* ����Y����*/
	LCD_ILI9341_Parameter(y>>8);
	LCD_ILI9341_Parameter(y&0xff);
	LCD_ILI9341_Parameter(y>>8);
	LCD_ILI9341_Parameter(y&0xff);		     
}

//  _ _ _ _ _ _
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
// |           |
//  - - - - - -
void LCD_OpenWindow(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{	
	LCD_ILI9341_CMD(0X2A); 				 /* ����X���� */
	LCD_ILI9341_Parameter( x >> 8 );	 /* �ȸ�8λ��Ȼ���8λ */
	LCD_ILI9341_Parameter( x & 0xff );	 /* ������ʼ��ͽ�����*/
	LCD_ILI9341_Parameter( (x+width-1) >> 8 );
	LCD_ILI9341_Parameter( (x+width-1) & 0xff );

	LCD_ILI9341_CMD(0X2B); 			     /* ����Y����*/
	LCD_ILI9341_Parameter( y >> 8 );
	LCD_ILI9341_Parameter( y & 0xff );
	LCD_ILI9341_Parameter( (y+height-1) >> 8);
	LCD_ILI9341_Parameter( (y+height-1) & 0xff);
}


void LCD_SetPoint(uint16_t x , uint16_t y , uint16_t color)	
{	
	LCD_SetCursor(x, y);
	LCD_ILI9341_CMD(0x2c);	         /* д���� */
	LCD_WR_Data(color);
}


uint16_t LCD_RD_data(void)	
{	
	uint16_t R=0, G=0, B=0 ;

	R = *(__IO uint16_t *)Bank1_LCD_D; 	  /*FIRST READ OUT DUMMY DATA*/
	R = *(__IO uint16_t *)Bank1_LCD_D;  	/*READ OUT RED DATA  */
	B = *(__IO uint16_t *)Bank1_LCD_D;  	/*READ OUT BLACK DATA*/
	G = *(__IO uint16_t *)Bank1_LCD_D;  	/*READ OUT GREEN DATA*/
	
    return (((R>>11)<<11) | ((G>>10)<<5) | (B>>11));
}

uint16_t LCD_GetPoint(uint16_t x , uint16_t y)
{ 
	uint16_t temp;

	LCD_SetCursor(x, y);
	LCD_ILI9341_CMD(0x2e);         /* ������ */
	temp=LCD_RD_data();
	return (temp);
}

/**************************************************************************************
 * ��  �� : TFTLCD��ʾ�����ַ�����
 * ��  �� : x ��, y ��, ascii ����ʾ�ַ�, color ��ʾ���ݵ���ɫ
 * ����ֵ : ��
 **************************************************************************************/
void LCD_DispChar(uint16_t x, uint16_t y, uint8_t ascii, uint16_t color)
{
	uint16_t page, column, temp, i;
	i = ascii - ' ';
	
	LCD_OpenWindow(x, y, STR_WIDTH, STR_HEIGHT);
	LCD_ILI9341_CMD(0X2C);	
	
	for( page=0; page < STR_HEIGHT; page++ )
	{
		temp = asc2_1206[i][page];
		for( column=0; column < STR_WIDTH; column++ )
		{
			if( temp & 0x01 )
			{
				LCD_WR_Data( color );
			}
			else
			{
				LCD_WR_Data( BACKGROUND );								
			}
			temp >>= 1;		
		}/* һ��д�� */
	}/* ȫ��д�� */
}

/**************************************************************************************
 * ��  �� : TFTLCD��ʾ�ַ�������
 * ��  �� : x ��, y ��, *pstr ����ʾ�ַ���, color ��ʾ���ݵ���ɫ
 * ����ֵ : ��
 **************************************************************************************/
void LCD_DispStr(uint16_t x, uint16_t y, uint8_t *pstr, uint16_t color)
{
	while( *pstr != '\0' )
	{
		if( x > (COLUMN-STR_WIDTH) )
		{
			x = 0;
			y += STR_HEIGHT;
		}
		if( y > (PAGE-STR_HEIGHT) )
		{
			x = 0;
			y = 0;
		}
		LCD_DispChar(x, y, *pstr, color);
		x += STR_WIDTH;
		pstr++;
	}
}

/**************************************************************************************
 * ��  �� : TFTLCD��ʾ�������ֺ���
 * ��  �� : x ��, y ��, num ����ʾ����, color ��ʾ���ݵ���ɫ
 * ����ֵ : ��
 **************************************************************************************/
void LCD_DisNum(uint16_t x, uint16_t y, uint32_t num, uint16_t color)
{
	uint32_t length = 0, temp = 0;
	temp = num;
	
	if( temp == 0 )
	{
		LCD_DispChar(x, y, '0', color);
		return;
	}
	
	while( temp )
	{// �õ�num�ĳ���
		temp /= 10;
		length ++;
	}
	
	while( num )
	{
		/* �Ӹ�λ��ʼ��ʾ */
		LCD_DispChar((x+STR_WIDTH*(length--)-STR_WIDTH), y, (num%10)+'0', color);
		num /= 10;
	}	
}
