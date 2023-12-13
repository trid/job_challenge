//
// Created by TriD on 12.12.2023.
//

#ifndef CHALLENGE_CABLE_TYPE_CRUD_MOCK_H
#define CHALLENGE_CABLE_TYPE_CRUD_MOCK_H

#include <string>
#include <vector>

#include <QJsonObject>

class CableTypeCRUDMock {
private:
    QVector<QJsonObject> _cableTypes;
public:
    // There would be implemented all the REST interactions in real world
    QJsonObject create(const QJsonObject& request);
    QJsonObject readAll(unsigned int limit = 100, const std::string after = "", bool descending = false) const;
    QJsonObject readOne(const QJsonObject& request);
    QJsonObject update(unsigned int id, const QJsonObject& request);
    void deleteItem(unsigned int id);
};


#endif //CHALLENGE_CABLE_TYPE_CRUD_MOCK_H
