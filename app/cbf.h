#pragma once

typedef enum cbf_status_s
{
    CBF_OK = 0, 
    CBF_FULL,   
    CBF_EMPTY,  
} cbf_status_t;

typedef struct cbf_s
{
	volatile uint16_t prod;
	volatile uint16_t cons; 
	uint16_t size;          
    uint8_t *buffer;       
} cbf_t;


/**
 @brief
 @param[in] cb 
 @return 
*/
uint16_t cbf_bytes_available(cbf_t *cb);
/**
 @brief 
 @param[in] cb 
 @return ver @ref cbf_status_s
*/
cbf_status_t cbf_flush(cbf_t *cb);
/**
 @brief 
 @param[in] cb 
 @param[out] c
 @return ver @ref cbf_status_s
*/
cbf_status_t cbf_get(cbf_t *cb, uint8_t *c);
/**
 @brief 
 @param[in] cb 
 @param[in] area 
 @param[in] size - tamanho da área de dados apontada por @p area.
 @return ver @ref cbf_status_s
*/
cbf_status_t cbf_init(cbf_t *cb, uint8_t *area, uint16_t size);
/**
 @brief
 @param[in] cb 
 @param[in] c 
 @return ver @ref cbf_status_s
*/
cbf_status_t cbf_put(cbf_t *cb, uint8_t c);

