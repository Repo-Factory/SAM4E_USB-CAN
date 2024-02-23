#include <cstdint>

#define LONG_MESSAGE_SIZE 64
#define SHORT_MESSAGE_SIZE 32

#define TOPIC_BYTES 2
#define SUBTOPIC_BYTES 2
#define FLAG_BYTES 2
#define RESERVED_BYTES 2
#define NON_DATA_BYTES TOPIC_BYTES+SUBTOPIC_BYTES+RESERVED_BYTES+FLAG_BYTES
#define LONG_MSG_DATA LONG_MESSAGE_SIZE - NON_DATA_BYTES

#define NUM_TOPICS 6
#define NUM_SUBTOPICS 6

typedef struct long_message_t
{
    unsigned char topic_id    [TOPIC_BYTES];
    unsigned char subtopic_id [SUBTOPIC_BYTES];
    unsigned char flags       [FLAG_BYTES];
    unsigned char data        [LONG_MSG_DATA];
    unsigned char reserved    [RESERVED_BYTES];
} long_message_t;

typedef enum device_category_t
{
    CONTROLLER,
    SYSTEM_MONITOR,
    POWER_SYSTEM,
    MOTION_CONTROL,
    RESERVED,
    AUXILLARY
} device_category_t;

// typedef enum device_topic_t
// {

// } device_topic_t;

