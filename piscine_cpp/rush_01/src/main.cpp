#include "ModuleHost.hpp"
#include "ModuleOS.hpp"
#include "ModuleDateTime.hpp"
#include "ModuleCPU.hpp"
#include "ModuleRAM.hpp"
#include "Core.hpp"
#include "IMonitorModules.hpp"
# include "ft_gkrellm.hpp"
# include <unistd.h>
# include <ncurses.h>

void     launch(int versionType)
{
    Core prog;
    if (versionType == TERMINAL)
    {
        prog.setDisplay(Core::NcurseDisp);
    }
    else if (versionType == GRAPHIC)
    {
        prog.setDisplay(Core::UiDisp);
    }
    prog.addModule(dynamic_cast<IMonitorModule*>( new ModuleDateTime() ));
    prog.addModule(dynamic_cast<IMonitorModule*>( new ModuleHost() ));
    prog.addModule(dynamic_cast<IMonitorModule*>( new ModuleOS() ));
    prog.addModule(dynamic_cast<IMonitorModule*>( new ModuleCPU() ));
    prog.addModule(dynamic_cast<IMonitorModule*>( new ModuleRAM() ));

    bool            display(true);
    int             c;
    std::clock_t	lTime = std::clock();
    std::clock_t	oTime;
    float           elapsedTime;

    prog.refresh();
    prog.init();
    while (display)
    {
        c = getch();

        if (c == 27 || c == 'q')
        {
            display = !display;
        }
        lTime = std::clock();
        elapsedTime = static_cast<float>(lTime - oTime) / CLOCKS_PER_SEC;
        if (elapsedTime > 0.5f)
        {
            prog.refresh();
            prog.render();
            oTime = lTime;
        }
    }
    prog.clear();
}

void    showUsage(void)
{
    std::cout << "usage: ./ft_gkrellm [option]" << std::endl;
    std::cout << "=> option: -t terminal version" << std::endl;
    std::cout << "           -g  graphic version" << std::endl;
}

int     main(int argc, char **argv)
{
    if (argc == 1 || (argv[1] && std::strcmp(argv[1] , "-t") == 0 ))
    {
        launch(TERMINAL);
    }
    else if ( argc == 2 && std::strcmp(argv[1],  "-g") == 0)
    {
        launch(GRAPHIC);
    }
    else
    {
        showUsage();
    }
    return 0;
}
