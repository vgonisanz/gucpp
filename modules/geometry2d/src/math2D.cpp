/*
  Template class
 */
#include "math2D.h"
#define LOG_TAG "Math2D"
#include "logger.h"

#include <math.h>
#include <stdlib.h>     /* srand, rand */

namespace threemonkeybits
{
  namespace math2d
  {
    int randomNumber(int mean, int desviation)
    {
    	if(desviation == 0)
    	{
    		return (int)((rand() % 1) + mean - desviation);
    	}
	    return (int)((rand() % (2 * desviation)) + mean - desviation);
    }
    int randomNumberInterval(const int min, const int max)
    {
    	const int maxReal = max + 1;
    	return (int)(  (rand() %  (maxReal - min) )  + min );	// Over 0
    }
    bool successfulChance(int chance, int totalChance)
    {
      bool success = (chance <= rand() % totalChance);
      if (!success)
      {
      	return true;
      }
      return false;
    }
    Point2D calculateRandomPoint2DInACircle(Point2D center, float radius)
    {
      Point2D returnValue = Point2D(0,0);
      int angle = randomNumberInterval(0, 359);	            // 0 --> 359 º
      float generatedX = radius * cos(angle * M_PI / 180);
      float generatedY = radius * sin(angle * M_PI / 180);
      returnValue.setPoint(center.x + generatedX, center.y + generatedY);
      return returnValue;
    }
    float randomValueBetween(float low, float high)
    {
      return (low + static_cast<float>(rand())/( static_cast<float>(RAND_MAX/(high-low))));
    }
  }
}
