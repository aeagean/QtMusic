#include "MusicPlayControl.h"

MusicPlayControl::MusicPlayControl()
{

}

bool MusicPlayControl::getIsStart()
{
    return m_isStart;
}

void MusicPlayControl::setIsStart(bool status)
{
    m_isStart = status;
    emit statusChanged();
}
