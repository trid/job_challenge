//
// Created by TriD on 12.12.2023.
//

#ifndef CHALLENGE_CABLE_TYPE_SUITE_H
#define CHALLENGE_CABLE_TYPE_SUITE_H

#include <QObject>

class CableTypeSuite: public QObject {
    Q_OBJECT

private slots:
    void createTest();
    void readTest();
    void updateTest();
    void deleteTest();
    // In real life there would be tests for wrong inputs
};

#endif //CHALLENGE_CABLE_TYPE_SUITE_H
