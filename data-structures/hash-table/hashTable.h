struct HashEntry
{
    long No;
    int Info;
    char Password[17];
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};

typedef unsigned int Index;
typedef Index Pos;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
int Find(long No,HashTable H);
void Insert(long No,HashTable H,char *Password);

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;
    
    H = (HashTable)malloc(sizeof(struct HashTbl));
    H->TableSize = TableSize;
    H->TheCells = (Cell *)malloc(sizeof(Cell)*(H->TableSize));
    for(i = 0;i < H->TableSize;i++)
        H->TheCells[i].Info = 0;
    return H;
}

int Find(long No,HashTable H)
{
    int CurrentPos;
    int CollisionNum;
    
    CollisionNum = 0;
    
    CurrentPos = No%(H->TableSize);
    while(H->TheCells[CurrentPos].Info != 0&&
          H->TheCells[CurrentPos].No != No)
    {
        CurrentPos += (2 * ++CollisionNum) - 1;
        if(CurrentPos >= H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(long No,HashTable H,char *p)
{
    long Pos;
    Pos = Find(No,H);
    if(H->TheCells[Pos].Info == 0)
    {
        H->TheCells[Pos].No = No;
        H->TheCells[Pos].Info = 1;
        strcpy(H->TheCells[Pos].Password,p);
    }
}
