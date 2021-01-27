#ifndef INVNODE_H
#define INVNODE_H
class InvNode
{
public:
	InvNode();
	~InvNode();
	int getAmount() { return amount; };
	int getItemNum() { return itemNum; };
	void setItemNum(int itemNum) { this->itemNum = itemNum; };
	void setAmount(int amount) { this->amount = amount; };
private:
	int amount;
	int itemNum;
};

#endif
