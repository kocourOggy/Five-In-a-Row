 //*****************************************************************

#include "Terminal.h"


//*****************************************************************

Terminal::Terminal()
{
	signal (SIGWINCH, NULL); // so we can resize terminal
	m_OrigTermSize = getSize();
	m_NewTermSize = getSize();
}

Terminal::~Terminal() { }

Coordinate Terminal::getSize(void)
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

	return Coordinate(w.ws_row, w.ws_col);
}

void Terminal::resize(const int x, const int y)
{
	if (m_NewTermSize.m_Row >= x && m_NewTermSize.m_Column >= y) return;

	std::string command("resize -s");
	command += " ";
	command += std::to_string(x);
	command += " ";
	command += std::to_string(y);
	system(command.c_str());

	m_NewTermSize.m_Row = x;
	m_NewTermSize.m_Column = y;
}

void Terminal::resizeToOrig()
{
	m_NewTermSize.m_Row = m_OrigTermSize.m_Row;
	m_NewTermSize.m_Column = m_OrigTermSize.m_Column;
	std::string command("resize -s");
	command += " ";
	command += std::to_string(m_NewTermSize.m_Row);
	command += " ";
	command += std::to_string(m_NewTermSize.m_Column);
	system(command.c_str());
}