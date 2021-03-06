// Copyright (c) 2017-2018 The PIVX developers
// Copyright (c) 2020 The VIDA developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZVDACONTROLDIALOG_H
#define ZVDACONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zvda/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZVdaControlDialog;
}

class CZVdaControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZVdaControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZVdaControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZVdaControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZVdaControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZVdaControlDialog(QWidget *parent);
    ~ZVdaControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZVdaControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZVdaControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZVDACONTROLDIALOG_H
