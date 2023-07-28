#include <cstddef>
#include "CocktailShakerSort.h"
#include "IntVector.h"

void CocktailShakerSort::operator()(IntVector &aContainer) const
{   
    size_t lLeft = 0;
    size_t lRight = aContainer.size() - 1;
    bool lSwapped = true;
    while (lSwapped)
    {
        lSwapped = false;
        for (size_t i = lLeft; i < lRight; i++)
        {
            if (aContainer[i] > aContainer[i + 1])
            {
                aContainer.swap(i, i + 1);
                lSwapped = true;
            }
        }
        if (!lSwapped)
        {
            break;
        }
        lSwapped = false;
        for (size_t i = lRight; i > lLeft; i--)
        {
            if (aContainer[i] < aContainer[i - 1])
            {
                aContainer.swap(i, i - 1);
                lSwapped = true;
            }
        }
        lLeft++;
        lRight--;
    }
}