#include "Forward.h"

using namespace std;

Forward::Forward()
{

	m_Health_Stat = ((rand() % 10) + 1) + ((rand() % 10) + 1) + ((rand() % 10) + 1) + ((rand() % 10) + 1) + ((rand() % 10) + 1);
	m_Shoot_Stat = ((rand() % 10) + 1) + ((rand() % 10) + 1) + ((rand() % 10) + 1);
	m_Pass_Stat = ((rand() % 10) + 1) + ((rand() % 5) + 1);
    m_Block_Stat = (((rand() % 10) + 1) + ((rand() % 5) + 1));
	m_Steal_Stat = (((rand() % 10) + 1) + ((rand() % 10) + 1));
	m_Handle_Stat = ((rand() % 10) + 1) + ((rand() % 10) + 1);
	m_Speed_Stat = ((rand() % 6) + 1);
	m_Recovery_Stat = ((rand() % 10) + 1);
	m_Open_Stat = ((rand() % 10) + 1) + ((rand() % 10) + 1);
	m_Tier = ((rand() % 3) + 1);
	m_AP = ((rand() % 10) + 1) + ((rand() % 5) + 1);;
	
}

Forward::~Forward()
{

}
