#include "triplecomponentmodel.hpp"


TripleComponentModel::TripleComponentModel(QObject *parent, HDTManager *view, hdt::TripleComponentRole compRole) :
    hdtManager(view), tripleComponentRole(compRole)
{

}

int TripleComponentModel::rowCount(const QModelIndex &parent) const
{
    if(hdtManager->getHDT() != NULL) {
        hdt::Dictionary &dict = hdtManager->getHDT()->getDictionary();
        switch(tripleComponentRole) {
        case hdt::SUBJECT:
            return dict.getNsubjects();
        case hdt::PREDICATE:
            return dict.getNpredicates();
        case hdt::OBJECT:
            return dict.getNobjects();
        }
    }
    return 0;
}

int TripleComponentModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant TripleComponentModel::data(const QModelIndex &index, int role) const
{
    if(hdtManager->getHDT() == NULL) {
        return QVariant();
    }

    switch(role) {
    case Qt::DisplayRole:
    {
        hdt::Dictionary &d = hdtManager->getHDT()->getDictionary();
        return d.idToString(index.row()+1, tripleComponentRole).c_str();
    }
    case Qt::FontRole:
    {
#if 0
        QFont font;
        font.setPointSize(10);
        return font;
#endif
    }
    case Qt::CheckStateRole:
        if(tripleComponentRole==hdt::PREDICATE) {
            return hdtManager->isPredicateActive(index.row()) ? Qt::Checked : Qt::Unchecked;
        }
    }
    return QVariant();
}

bool TripleComponentModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(hdtManager->getHDT() == NULL) {
        return false;
    }

    cout << "SetData" << endl;
    switch(role) {
        case Qt::CheckStateRole:
        if(tripleComponentRole==hdt::PREDICATE) {
            hdtManager->setPredicateActive(index.row(), value.toBool());
        }
    }
    return true;
}

QVariant TripleComponentModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    switch(role) {
    case Qt::DisplayRole:
    {
        if(orientation == Qt::Horizontal) {
            switch(tripleComponentRole) {
            case hdt::SUBJECT:
                return "Subject";
            case hdt::PREDICATE:
                return "Predicate";
            case hdt::OBJECT:
                return "Object";
            }
        } else {
            return QString::number(section+1);
        }
        break;
    }
    case Qt::SizeHintRole:
    {
    }
    }

    return QVariant();
}

Qt::ItemFlags TripleComponentModel::flags(const QModelIndex &index) const
{
    //cout << "Flags" << endl;
    if(tripleComponentRole == hdt::PREDICATE) {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
    } else {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
}

void TripleComponentModel::itemsChanged(unsigned int ini, unsigned fin)
{
    QModelIndex first = createIndex(ini, 1);
    QModelIndex last = createIndex(fin, 1);
    emit dataChanged(first, last);
}

void TripleComponentModel::notifyLayoutChanged()
{
    emit layoutChanged();
}