#include <iostream>
#include <stdexcept>

#define DEBUG

using namespace std;

class Matrix
{
public:
    Matrix(int width, int height) : width(width), height(height)
    {
        arr = new int[width * height];
        if (nullptr == arr)
        {
            throw std::overflow_error("Not enough heap.");
        }
    }

    int At(int x, int y)
    {
        return arr[Index(x, y)];
    }

    void Set(int x, int y, int value)
    {
        arr[Index(x, y)] = value;
    }

    void SetAll(int value)
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                Set(i, j, value);
    }

    void Print()
    {
        cout << endl;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                cout << arr[i * width + j] << ", ";
            cout << endl;
        }
        cout << endl;
    }

    int Index(int x, int y)
    {
        return (x * width + y);
    }

protected:
    int *arr = nullptr;
    int width = 0;
    int height = 0;

private:
};

class Spiral : public Matrix
{
public:
    Spiral(int n) : Matrix(n, n), size(n), ringSize(size) {}
    Spiral(int n, int seed) : Matrix(n, n), size(n), ringSize(size), seed(seed) {}

    void Draw(void)
    {
        start_x = 0;
        start_y = 0;
        start_val = seed;
        limit = getLengthOfRing();

        _Draw();
    }

private:
    int size = 0;
    int ringSize = 0;
    int seed = 0;

    int dirRow[4] = {0, 1, 0, -1};
    int dirCol[4] = {1, 0, -1, 0};

    int currDirRowIdx = 0;
    int currDirColIdx = 0;

    int currDirRowInc = dirRow[currDirRowIdx];
    int currDirColInc = dirCol[currDirColIdx];

    int start_x = 0;
    int start_y = 0;
    int start_val = 0;
    int limit = 0;

    int getLengthOfRing(void)
    {
        return (4 * (ringSize - 1));
    }

    void SwitchDirection(void)
    {
        currDirRowIdx = (currDirRowIdx + 1) % 4;
        currDirColIdx = (currDirColIdx + 1) % 4;

        currDirRowInc = dirRow[currDirRowIdx];
        currDirColInc = dirCol[currDirColIdx];
    }

    void Increment(int &x, int &y)
    {
        x += currDirRowInc;
        y += currDirColInc;
    }

    void Decrement(int &x, int &y)
    {
        x -= currDirRowInc;
        y -= currDirColInc;
    }

    bool IsWithinBounds(int x, int y)
    {
        return ((x < (start_x + ringSize) && y < (start_y + ringSize)) && (x >= start_x && y >= start_y));
    }

    void DecRingSizeBy2(void)
    {
        ringSize -= 2;
    }

    void _Draw()
    {
        if (limit < 0)
            return;

        if (limit == 0)
        {
            this->Set(start_x, start_y, start_val);
            return;
        }

        int val = start_val;

        int i = start_x, j = start_y, count = 0;
        while (count < limit)
        {
            this->Set(i, j, val++);
#ifdef DEBUG
            cout << count << ": Val at (" << i << "," << j << ") set to " << val - 1 << endl;
#endif
            Increment(i, j);
            if (!IsWithinBounds(i, j))
            {
                // you have gone off the edge, walk back 1, switch directions
                // and go forward one in the new direction.
                Decrement(i, j);
                SwitchDirection();
                Increment(i, j);
            }
            count++;
        }

        // finished drawing the outer ring, move to the inner ring.
        Decrement(i, j);
        SwitchDirection();
        Increment(i, j);

        DecRingSizeBy2();
        start_x = i;
        start_y = j;
        start_val = val;
        limit = getLengthOfRing();

        _Draw();
    }
};

int main(void)
{
    try
    {
        Spiral s(3);

        s.SetAll(45);
        s.Print();

        s.Draw();
        s.Print();

        Spiral q(4, 10);
        q.Draw();
        q.Print();

        Spiral r(5);
        r.Draw();
        r.Print();

        Spiral t(6, 99);
        t.Draw();
        t.Print();
    }
    catch (std::overflow_error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
