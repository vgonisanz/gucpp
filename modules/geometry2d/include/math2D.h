#pragma once

#include "point2D.h"

namespace threemonkeybits
{
	namespace math2d
	{
		/**
		 * \brief Return a random number center on mean, with max desviation from center: desviation
		 *
		 * Description:	range center on mean, with +-desviation
		 *
		 * \param[in]		mean
		 * \param[in]		desviation
		 * \return			a random number
		 *
		 */
		int randomNumber(int mean, int desviation);
		/**
		 * \brief Return a random number center on mean, with max and min using int
		 *
		 * Description:	range center between max and min
		 *
		 * \param[in]		max number
		 * \param[in]		min number
		 * \return			a random number
		 *
		 */
		int randomNumberInterval(const int min, const int max);
		/**
		 * \brief Return true = chance successful or false
		 *
		 *
		 */
		bool successfulChance(int chance, int totalChance);
		/**
		 * \brief Calculate a CCPoint in a circle centered on center point, with radius given
		 */
		Point2D calculateRandomPoint2DInACircle(Point2D center, float radius);
		/**
		 * \brief Calculate a CCPoint in a circle centered on center point, with radius given using float
		 */
		float randomValueBetween(float low, float high);
	}
}
