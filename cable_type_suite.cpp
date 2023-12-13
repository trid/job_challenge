//
// Created by TriD on 12.12.2023.
//

#include "cable_type_suite.h"

#include <QJsonArray>
#include <QTest>

#include "cable_type_crud_mock.h"
#include "cable_type_builder.h"

void CableTypeSuite::createTest() {
    CableTypeCRUDMock cableTypeCrudMock;
    CableTypeBuilder cableTypeBuilder;
    cableTypeBuilder.resetId();
    auto cableType = cableTypeBuilder.build();

    auto createdCableType = cableTypeCrudMock.create(cableType);
    auto idIter = createdCableType.find("id");
    QVERIFY(idIter != createdCableType.end());

    cableType.insert("id", *idIter);
    QCOMPARE(createdCableType, cableType);
}

void CableTypeSuite::readTest() {
    CableTypeCRUDMock cableTypeCrudMock;
    CableTypeBuilder cableTypeBuilder;
    cableTypeBuilder.resetId();
    auto cableType = cableTypeBuilder.build();
    auto createdCableType = cableTypeCrudMock.create(cableType);

    auto cables = cableTypeCrudMock.readAll();

    QVERIFY(cables["total"].isDouble());
    QVERIFY(cables["total"].toInt() == 1);
    QVERIFY(cables["entities"].isArray());

    auto entities = cables["entities"].toArray();
    QCOMPARE(createdCableType, entities[0].toObject());
}

void CableTypeSuite::updateTest() {
    CableTypeCRUDMock cableTypeCrudMock;
    CableTypeBuilder cableTypeBuilder;
    cableTypeBuilder.resetId();
    auto cableType = cableTypeBuilder.build();
    auto createdCableType = cableTypeCrudMock.create(cableType);
    createdCableType["size"].toObject()["value"] = 10.0;

    auto updatedCable = cableTypeCrudMock.update(0, createdCableType);

    QCOMPARE(createdCableType, updatedCable);
}

void CableTypeSuite::deleteTest() {
    CableTypeCRUDMock cableTypeCrudMock;
    CableTypeBuilder cableTypeBuilder;
    cableTypeBuilder.resetId();
    auto cableType = cableTypeBuilder.build();
    auto createdCableType = cableTypeCrudMock.create(cableType);

    cableTypeCrudMock.deleteItem(0);

    auto cables = cableTypeCrudMock.readAll();
    QVERIFY(cables["total"].isDouble());
    QVERIFY(cables["total"].toInt() == 0);
}

#include "cable_type_suite.moc"

QTEST_MAIN(CableTypeSuite)