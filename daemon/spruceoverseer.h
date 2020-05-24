#ifndef SPRUCEOVERSEER_H
#define SPRUCEOVERSEER_H

#include "global.h"
#include "market.h"
#include "coinamount.h"
#include "misctypes.h"
#include "diffusionphaseman.h"

#include <QString>
#include <QVector>
#include <QMap>
#include <QDir>
#include <QObject>
#include <QTimer>

class AlphaTracker;
class Spruce;
class Engine;
class QTimer;

class SpruceOverseer : public QObject
{
    Q_OBJECT

    friend class SpruceOverseerTest;

public:
    explicit SpruceOverseer( Spruce *_spruce );
    ~SpruceOverseer();

    static QString getSettingsPath() { return Global::getTraderPath() + QDir::separator() + "spruce.settings"; }
    void loadSettings();
    void saveSettings();
    void loadStats();
    void saveStats();

    const QString &getLastMidspreadPhaseOutput() const { return m_last_midspread_output; }

    QMap<quint8, Engine*> engine_map;
    AlphaTracker *alpha{ nullptr };
    Spruce *spruce{ nullptr };
    QTimer *spruce_timer{ nullptr };

signals:
    void gotUserCommandChunk( QString &s ); // loaded settings file

public Q_SLOTS:
    void onSpruceUp();
    void onSaveSpruceSettings();

private:
    void runCancellors( Engine *engine, const QString &market, const quint8 side, const QString &strategy, const Coin &flux_price );
    void cancelForReason( Engine *const &engine, const Market &market, const quint8 side, const quint8 reason );

    void adjustSpread( TickerInfo &spread, Coin limit, quint8 side, Coin &default_ticksize, bool expand = true );
    void adjustTicksizeToSpread( Coin &ticksize, TickerInfo &spread, const Coin &ticksize_minimum );
    TickerInfo getSpreadLimit( const QString &market, bool order_duplicity = false );
    TickerInfo getMidSpread( const QString &market );
    TickerInfo getSpreadForSide( const QString &market, quint8 side, bool order_duplicity = false, bool taker_mode = false, bool include_limit_for_side = false, bool is_randomized = false, Coin greed_reduce = Coin() );
    Coin getPriceTicksizeForMarket( const Market &market ) const;

    QMap<QString,Coin> m_last_spread_distance_buys;
    QMap<QString,Coin> m_last_spread_distance_sells;
    QString m_last_midspread_output;

    DiffusionPhaseMan m_phase_man;

    QTimer *autosave_timer{ nullptr };
};

#endif // SPRUCEOVERSEER_H
