#ifndef TYPES_H
#define TYPES_H
#include <QString>
#define INVALID_TOPIC -1
namespace flash_cards {

typedef int Result;
typedef int TopicID;

struct Topic
{
    int id = -1;
    QString name = QString();
    int it_count = 0;
};

struct Question {
    int id = -1;


};
}

#endif // TYPES_H
