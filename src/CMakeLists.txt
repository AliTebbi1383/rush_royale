set(app_SRCS
    # Pages
		Pages/start.h
		Pages/start.cpp
		Pages/start.ui
		Pages/mainwindow.h
		Pages/mainwindow.cpp
		Pages/mainwindow.ui
    # Components
		Components/startpagegraphicsview.h
		Components/startpagegraphicsview.cpp
		Components/gameboard.h
		Components/gameboard.cpp
		Components/gamegraphics.h
		Components/gamegraphics.cpp
		Components/agentdraggablegraphics.h
		Components/agentdraggablegraphics.cpp
		Components/agentgraphics.h
		Components/agentgraphics.cpp
		Components/boardgraphics.h
		Components/boardgraphics.cpp
		Components/elixirgraphics.h
		Components/elixirgraphics.cpp
		Components/cardgraphics.h
		Components/cardgraphics.cpp
    # Game
		Game/agent.h
		Game/agent.cpp
		Game/agentcontext.h
		Game/agentcontext.cpp
		Game/firststrikeragent.h
		Game/firststrikeragent.cpp
		Game/strikeragent.h
		Game/strikeragent.cpp
		Game/endstrikeragent.h
		Game/endstrikeragent.cpp
		Game/randomstrikeragent.h
		Game/randomstrikeragent.cpp
		Game/maxhealthstrikeragent.h
		Game/maxhealthstrikeragent.cpp
		Game/blockeragent.h
		Game/blockeragent.cpp
		Game/bomberblockeragent.h
		Game/bomberblockeragent.cpp
		Game/trapblockeragent.h
		Game/trapblockeragent.cpp
		Game/enemy.h
		Game/enemy.cpp
		Game/enemycontext.h
		Game/enemycontext.cpp
		Game/bossenemy.h
		Game/bossenemy.cpp
		Game/freezerbossenemy.h
		Game/freezerbossenemy.cpp
		Game/disarmerbossenemy.h
		Game/disarmerbossenemy.cpp
		Game/eraserbossenemy.h
		Game/eraserbossenemy.cpp
		Game/soldierenemy.h
		Game/soldierenemy.cpp
		Game/runnersoldierenemy.h
		Game/runnersoldierenemy.cpp
		Game/sheildersoldierenemy.h
		Game/sheildersoldierenemy.cpp
		Game/gamecontext.h
		Game/gamecontext.cpp
    # main
		gameresourcemanager.h
		gameresourcemanager.cpp
		Logger.h
		Logger.cpp
    main.cpp)

qt_add_executable(rush_royale MANUAL_FINALIZATION ${app_RESOURCES} ${app_SRCS})

target_link_libraries(rush_royale PRIVATE Qt6::Widgets)

qt_finalize_executable(rush_royale)
