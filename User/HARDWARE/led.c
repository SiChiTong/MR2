
#include "led.h"

void task4_task(void *pvParameters)
{
    BeginWarnBuzzer();
    for(;;)
    {
        for (int i = 0; i < 8; i++)
            flow_led_off(i);

        vTaskDelay(500);

        for (int i = 0; i < 8; i++)
            flow_led_on(i);

        vTaskDelay(500);
    }

}


void led_configuration(void)
{

    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOF_CLK_ENABLE();           //����GPIOBʱ��
    __HAL_RCC_GPIOE_CLK_ENABLE();           //����GPIOBʱ��
    __HAL_RCC_GPIOG_CLK_ENABLE();           //����GPIOBʱ��

    GPIO_Initure.Pin=GPIO_PIN_14;
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //�������
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
    HAL_GPIO_Init(GPIOF,&GPIO_Initure);

    GPIO_Initure.Pin=GPIO_PIN_11;
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);

    led_green_off();
    led_red_off();

    GPIO_Initure.Pin=GPIO_PIN_1 | GPIO_PIN_2 |GPIO_PIN_3 |GPIO_PIN_4 |GPIO_PIN_5 |GPIO_PIN_6 |GPIO_PIN_7 |GPIO_PIN_8 ;
    HAL_GPIO_Init(GPIOG,&GPIO_Initure);

    flow_led_off( GPIO_PIN_1 | GPIO_PIN_2 |GPIO_PIN_3 |GPIO_PIN_4 |GPIO_PIN_5 |GPIO_PIN_6 |GPIO_PIN_7 |GPIO_PIN_8 ) ;

}


void led_green_off(void)
{
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_14,GPIO_PIN_SET);
}
void led_green_on(void)
{
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_14,GPIO_PIN_RESET);
}
void led_green_toggle(void)
{
    HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_14);
}

void led_red_off(void)
{
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);
}
void led_red_on(void)
{
    HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_RESET);
}
extern void led_red_toggle(void)
{
    HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_11);
}

void flow_led_on(uint16_t num)
{
    HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8 >> num,GPIO_PIN_RESET);
}
void flow_led_off(uint16_t num)
{
    HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8 >> num,GPIO_PIN_SET);
}
void flow_led_toggle(uint16_t num)
{
    HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_8 >> num );
}