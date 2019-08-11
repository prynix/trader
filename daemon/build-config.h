#ifndef BUILDCONFIG_H
#define BUILDCONFIG_H

#define BUILD_VERSION "1.73k"

/// select your exchange
//#define EXCHANGE_BITTREX
//#define EXCHANGE_POLONIEX
#define EXCHANGE_BINANCE

/// where to print logs
#define PRINT_LOGS_TO_CONSOLE
#define PRINT_LOGS_TO_FILE
#define PRINT_LOGS_TO_FILE_COLOR

/// what to log
//#define PRINT_LOGS_WITH_FUNCTION_NAMES
#define PRINT_ENABLED_SSL_CIPHERS
//#define PRINT_DISABLED_SSL_CIPHERS

/// allow remote wss?
#define WSS_INTERFACE

/// build options
//#define EXTRA_NICE // be extra nice to the exchange api
//#define TRYPHE_BUILD


#endif // BUILDCONFIG_H
