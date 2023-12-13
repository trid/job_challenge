//
// Created by TriD on 12.12.2023.
//

#include "cable_type_builder.h"

CableTypeBuilder::CableTypeBuilder() {
    _state = QJsonObject{
            {"identifier",    "5f3bc9e2502422053e08f9f1"},
            {"catid",         "10-al-1c-trxple"},
            {"currentPrice",  QJsonObject{{"value", 31086.00},
                                          {"unit",  "USD"}}},
            {"description",   "CABLE,COPPER, 15KV, 500 KCMIL FILLED COMPACT, 3-1/C TRIPLEX, 175 MIL EPR, 1/0 COPPER"},
            {"diameter",      QJsonObject{
                    {"published", QJsonObject{{"value", 3.25},
                                              {"unit",  "in"}}}
            }},
            {"material",      QJsonObject{
                    {"copper", QJsonObject{{"value", 5737.0},
                                           {"unit",  "lb/mft"}}},
                    {"weight", QJsonObject{{"net", QJsonObject{{"value", 7254.0},
                                                               {"unit",  "lb/mft"}}}}}
            }},
            {"specification", "CBL-6005-E"},
            {"airGap",        0.5},
            {"type",          "Flat Strap"}
    };
}

void CableTypeBuilder::resetId() {
    _state.remove("id");
}

QJsonObject CableTypeBuilder::build() const {
    return _state;
}