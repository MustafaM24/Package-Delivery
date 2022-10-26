struct BOX
{
    int length;
    int width;
    int height;

    BOX()
    {
        length = width = height = 0;
    }


    int V()
    {
        int V = length*width*height;
        return V;
    }
};
