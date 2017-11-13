#ifndef TYPES_H
#define TYPES_H
#include <QString>
namespace flash_cards {

typedef bool Result;

struct Topic
{
    int id;
    QString name;
    int it_count;
};

}

#endif // TYPES_H
