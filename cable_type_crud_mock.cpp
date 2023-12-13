//
// Created by TriD on 12.12.2023.
//

#include "cable_type_crud_mock.h"

#include <QJsonArray>

QJsonObject CableTypeCRUDMock::create(const QJsonObject& request) {
    auto id = QString::number(_cableTypes.size());
    _cableTypes.push_back(request);
    _cableTypes.back().insert("id", id);
    return _cableTypes.back();
}

QJsonObject CableTypeCRUDMock::readAll(unsigned int limit, const std::string after, bool descending) const {
    // I'm too lazy to implement real logic here
    QJsonArray items;
    for (auto item: _cableTypes) {
        items.push_back(item);
    }

    return QJsonObject{
            {"entities", items},
            {"total",    _cableTypes.size()},
            {"page",     0},
            {"next",     ""}
    };
}

QJsonObject CableTypeCRUDMock::update(unsigned int id, const QJsonObject& request) {
    _cableTypes[id] = request;
    return request;
}

void CableTypeCRUDMock::deleteItem(unsigned int id) {
    // Here we have an error when cable type id not equal to id in vector.
    // It does not matter for our case, so we won't fix it now
    _cableTypes.remove(id);
}