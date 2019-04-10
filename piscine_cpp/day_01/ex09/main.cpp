#include "Logger.hpp"

int     main( void ) {
    Logger   logger = Logger("logfile.log");

    logger.log("console", "Lolilol");
    logger.log("logfile", "Lolilol");

    logger.log("console", "C'est la console (que console)");

    logger.log("pasbonfile", "Quoi ?? (rien du tout)");

    logger.log("console", "The last one...");
    logger.log("logfile", "The last one...");

    return 0;
}
