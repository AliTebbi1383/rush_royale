set(app_SRCS
    # Pages
    Pages/start.h Pages/start.cpp Pages/start.ui
    Pages/mainwindow.h Pages/mainwindow.cpp Pages/mainwindow.ui
    # Components
    Components/startpagegraphicsview.h Components/startpagegraphicsview.cpp
    Components/gameboard.h Components/gameboard.cpp
    Components/gamegraphics.h Components/gamegraphics.cpp
    Components/agentgraphics.h Components/agentgraphics.cpp
    Components/boardgraphics.h Components/boardgraphics.cpp
    # main
    gameresourcemanager.h gameresourcemanager.cpp
    Logger.h
    main.cpp
)

qt_add_executable(rush_royale
    MANUAL_FINALIZATION
    ${app_RESOURCES}
    ${app_SRCS}
)

target_link_libraries(rush_royale PRIVATE
    Qt6::Widgets
)

qt_finalize_executable(rush_royale)
