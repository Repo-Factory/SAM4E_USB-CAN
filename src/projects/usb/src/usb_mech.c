#include "usb_mech.h"

#define BYTE_MASK 0xFF
#define CLEAR_MASK 0x00
#define BYTE_SIZE 8

/* 
 * @brief Handler functions will go here. To perform specific function, deference this array at the appropriate topic/subtopic index
 */
const void (*topics[NUM_TOPICS][NUM_SUBTOPICS])(const unsigned char* data) =
{
//     {topic1_subtopic1, topic1_subtopic2},
//     {topic2_subtopic1, topic2_subtopic2}
};

/*
 * @brief place appropriate values of message into corresponding field of long_message_t struct
 * @param field - pass in an empty struct of long_message_t and the answer will be "returned" here  
 */
void extract_fields(const unsigned char* message, long_message_t* fields, const int message_size) 
{
    for (int i = 0; i < TOPIC_BYTES; i++) {
        fields->topic_id[i] = message[i];
    }
    for (int i = 0; i < SUBTOPIC_BYTES; i++) {
        fields->subtopic_id[i] = message[TOPIC_BYTES + i];
    }
    for (int i = 0; i < SUBTOPIC_BYTES; i++) {
        fields->flags[i] = message[TOPIC_BYTES + SUBTOPIC_BYTES + i];
    }
    for (int i = 0; i < LONG_MSG_DATA; i++) {
        fields->data[i] = message[TOPIC_BYTES + SUBTOPIC_BYTES + FLAG_BYTES + i];
    }
    for (int i = 0; i < RESERVED_BYTES; i++) {
        fields->reserved[i] = message[TOPIC_BYTES + SUBTOPIC_BYTES + FLAG_BYTES + LONG_MSG_DATA + i];
    }
}

/*
 * @brief compose an array value into integer value with bit manipulations
 * @param field - pass in member of long_message_t struct here
 */
int extract_field_value(const unsigned char* field, const int field_size)
{
    int field_value = 0;
    for (int i = 0; i < field_size; i++) {
        field_value |= field[i] << (i * BYTE_SIZE);
    }
    return field_value;
}

void HANDLE_MESSAGE(const unsigned char* message, const int message_size)
{
    long_message_t fields;
    extract_fields(message, &fields, message_size);
    const int topic = extract_field_value(fields.topic_id, TOPIC_BYTES);
    const int subtopic = extract_field_value(fields.subtopic_id, SUBTOPIC_BYTES);
    const int flags = extract_field_value(fields.flags, FLAG_BYTES);
    const int reserved = extract_field_value(fields.reserved, RESERVED_BYTES);
    topics[topic][subtopic](fields.data);
}