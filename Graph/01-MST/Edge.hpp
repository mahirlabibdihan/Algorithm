#ifndef __EDGE__
#define __EDGE__
class Edge
{
public:
    int from, to;
    float weight;
    Edge() {}
    Edge(int from, int to, float weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    bool operator<(const Edge &e)
    {
        return this->weight < e.weight;
    }
};
#endif