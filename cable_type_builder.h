//
// Created by TriD on 12.12.2023.
//

#ifndef CHALLENGE_CABLE_TYPE_BUILDER_H
#define CHALLENGE_CABLE_TYPE_BUILDER_H

#include <QJsonObject>

class CableTypeBuilder {
private:
    QJsonObject _state;
public:
    CableTypeBuilder();

    // Put setters for CableType parameters here
    void resetId();

    QJsonObject build() const;
};


#endif //CHALLENGE_CABLE_TYPE_BUILDER_H
