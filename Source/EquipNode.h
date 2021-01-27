#ifndef EQUIPNODE_H
#define EQUIPNODE_H

class EquipNode
{
public:
	EquipNode();
	
	~EquipNode();
	int getEquipNum()
	{
		return equipNum;
	}
	int getMaxDuribilty()
	{
		return maxDuribilty;

	}
	int getDuribility()
	{
		return duribility;
	}
	bool getBroken()
	{
		return broken;
	}
	int getEquipType()
	{
		return equipType;
	}
	void setAll(int equipNum, int equipType, int maxDuribilty, int duribility, bool broken)
	{
		this->equipNum = equipNum;
		this->equipType = equipType;
		this->maxDuribilty = maxDuribilty;
		this->duribility = duribility;
		this->broken = broken;
	}
	int row;
	int col;
	bool isEquiped = false;
private:
	int equipNum=0;
	int equipType = -1;
	int maxDuribilty=9999;
	int duribility=9999;
	bool broken=false;
	
};

#endif
