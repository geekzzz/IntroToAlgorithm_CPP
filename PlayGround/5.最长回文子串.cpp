// #include "MFSpringBoneCollisionDetectionMethod.h"

// bool MFSpringBoneCollisionDetectionMethod::SphereSphereCollisionDetection(const FVector& center0, const float radius0, const FVector& center1, const float radius1, FVector& finalCenter)
// {
// 	float r = radius0 + radius1;
// 	float r2 = r * r;

// 	FVector d = center0 - center1;
// 	float len2 = d.SizeSquared();

// 	finalCenter = center0;

// 	if (len2 > 0 && len2 < r2) 
// 	{
// 		float len = FMath::Sqrt(len2); 
// 		finalCenter = center1 + d * (r / len);
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }
// bool MFSpringBoneCollisionDetectionMethod::SphereCapsuleCollisionDetectionSegment(const FVector& sphereCenter, const float sphereRadius,
// 	const FVector& capsuleP0, const FVector& capsuleP1, const float capsuleRadius, FVector& result)
// {
// 	result = sphereCenter;
// 	////distance to segment
// 	FVector ab = capsuleP1 - capsuleP0;
// 	FVector av = sphereCenter - capsuleP0;
// 	FVector bv = sphereCenter - capsuleP1;
// 	float distance;
// 	if (FVector::DotProduct(ab, av) <= 0.0f)
// 		distance = FMath::Sqrt(FVector::DotProduct(av, av));
// 	else if (FVector::DotProduct(bv, ab) >= 0.0f)
// 		distance = FMath::Sqrt(FVector::DotProduct(bv, bv));
// 	else
// 	{
// 		FVector abav = FVector::CrossProduct(ab, av);
// 		float modab = FMath::Sqrt(FVector::DotProduct(ab, ab));
// 		distance = FMath::Sqrt(FVector::DotProduct(abav, abav))/ FMath::Sqrt(FVector::DotProduct(ab, ab));
// 	}
// 	float radiusCapSphe = capsuleRadius + sphereRadius;
// 	if (distance > radiusCapSphe)
// 		return false;

// 	FVector globalDir = capsuleP1 - capsuleP0;
// 	float middleAxisLen = globalDir.Size();
// 	float r = capsuleRadius + sphereRadius;
// 	float r2 = r * r;
// 	FVector d0 = sphereCenter - capsuleP0;
// 	FVector d1 = sphereCenter - capsuleP1;
// 	float dl = middleAxisLen * middleAxisLen;
// 	float projectLen = FVector::DotProduct(d0, globalDir.GetSafeNormal());
// 	result = sphereCenter;
// 	if (projectLen <= 0 || projectLen >= middleAxisLen)
// 	{
// 		float len2 = (projectLen <= 0) ? d0.SizeSquared() : d1.SizeSquared();
// 		if (len2 > 0 && len2 < r2)
// 		{
// 			result = (projectLen <= 0) ? capsuleP0 + d0* (r / FMath::Sqrt(len2)) : capsuleP1 + d1* (r / FMath::Sqrt(len2));
// 			return true;
// 		}
// 	}
// 	else if (dl > 0)
// 	{
// 		d0 -= globalDir * projectLen /dl;
// 		float len2 = d0.SizeSquared();
// 		if (len2 > 0 && len2 < r2)
// 		{
// 			result = sphereCenter + d0 * ((r - FMath::Sqrt(len2)) / FMath::Sqrt(len2));
// 			return true;
// 		}
// 	}
// 	return false;
// }

// bool MFSpringBoneCollisionDetectionMethod::SphereCapsuleCollisionDetection(const FVector& sphereCenter, const float sphereRadius,
// 	const FVector& capsuleP0, const FVector& capsuleP1, const float capsuleRadius, FVector& finalPos) 
// {
// 	FVector globalDir = capsuleP1 - capsuleP0;
// 	float middleAxisLen = globalDir.Size();

// 	float r = capsuleRadius + sphereRadius;
// 	float r2 = r * r;
// 	FVector d = sphereCenter - capsuleP0;
// 	float t = FVector::DotProduct(d, globalDir.GetSafeNormal());
// 	finalPos = sphereCenter;
// 	if (t <= 0)
// 	{
// 		// check sphere1
// 		float len2 = d.SizeSquared();
// 		if (len2 > 0 && len2 < r2)
// 		{
// 			float len = FMath::Sqrt(len2);
// 			finalPos = capsuleP0 + d * (r / len);
// 			return true;
// 		}
// 	}
// 	else
// 	{
// 		float dl = middleAxisLen * middleAxisLen;
// 		if (t >= middleAxisLen)
// 		{
// 			d = sphereCenter - capsuleP1;
// 			float len2 = d.SizeSquared();
// 			if (len2 > 0 && len2 < r2)
// 			{
// 				float len = FMath::Sqrt(len2);
// 				finalPos = capsuleP1 + d * (r / len);
// 				return true;
// 			}
// 		}
// 		else if (dl > 0)
// 		{
// 			// check cylinder
// 			t /= dl;
// 			d -= globalDir * t;
// 			float len2 = d.SizeSquared();
// 			if (len2 > 0 && len2 < r2)
// 			{
// 				float len = FMath::Sqrt(len2);
// 				finalPos = sphereCenter + d * ((r - len) / len);
// 				return true;
// 			}
// 		}
// 	}

// 	return false;
// }

// bool MFSpringBoneCollisionDetectionMethod::MovingSphereSphereCollisionDetection(const FVector& center0, const float radius0, const FVector& center1, const float radius1, FVector v0, FVector v1,
// 	float &t) 
// {
// 	FVector s = center1 - center0;
// 	FVector v = v1 - v0;

// 	float r = radius0 + radius1;
// 	float c = FVector::DotProduct(s, s) - r * r;

// 	if (c < 0.0f) 
// 	{
// 		t = 0.0f;
// 		return true;
// 	}
// 	float a = FVector::DotProduct(v, v);
// 	if (a < SMALL_NUMBER) 
// 	{
// 		return false;
// 	}
// 	float b = FVector::DotProduct(v, s);
// 	if (b >= 0.0f) 
// 	{
// 		return false;
// 	}

// 	float d = b * b - a * c;
// 	if (d < 0.0f) return false;

// 	t = (-b - FMath::Sqrt(d)) / a;
// 	return true;
// }

// bool MFSpringBoneCollisionDetectionMethod::SphereCapsuleCollisionDetectionCCD(const FVector& sphereCenter, const FVector& prevSphereCenter, const float sphereRadius,
// 	const FVector& capsuleP0, const FVector& capsuleP1, const float capsuleRadius, FVector& finalPos)
// {
// 	FVector v0 = sphereCenter - prevSphereCenter;
// 	FVector v1 = capsuleP1 - capsuleP0;

// 	float t = 0.0f;
// 	bool res = MovingSphereSphereCollisionDetection(prevSphereCenter, sphereRadius, capsuleP0, capsuleRadius, v0, v1, t);

// 	if (res) {
// 		FVector collidingPoint = prevSphereCenter + t * v0;
// 		finalPos = collidingPoint;
// 	}
// 	return res;
// }

// void ClosestPtPointSegment(FVector point, FVector segP0, FVector segP1, float &t, FVector &d) {
// 	FVector seg = segP1 - segP0;

// 	t = FVector::DotProduct(point - segP0, seg);
// 	if (t <= 0.0f) {
// 		t = 0.0f;
// 		d = segP0;
// 	}
// 	else {
// 		float denom = FVector::DotProduct(seg, seg);
// 		if (t >= denom) {
// 			t = 1.0f;
// 			d = segP1;
// 		}
// 		else {
// 			t = t / denom;
// 			d = segP0 + t * seg;
// 		}
// 	}
// }

// bool MFSpringBoneCollisionDetectionMethod::SphereSphereCollisionDetectionCCD(const FVector& center0, const FVector& prevcenter0, const float radius0, 
// 	const FVector& center1, const float radius1, FVector& finalCenter) 
// {
// 	FVector closestPoint = FVector(0.0f, 0.0f, 0.0f);
// 	float t = 0.0f;

// 	ClosestPtPointSegment(center1, center0, prevcenter0, t, closestPoint);

// 	FVector normal = closestPoint - center1;
// 	float dis = normal.Size();
// 	if (dis < (radius0 + radius1)) {
// 		finalCenter = center1 + (radius0 + radius1) * normal.GetSafeNormal();
// 		return true;
// 	}
// 	else {
// 		return false;
// 	}
// }


/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
string expand(const string& s, int j, int k)
{
    int len = 0;
    if (j == k)
        len = -1;
    else
        len = 0;
    int jj = j;
    int kk = k;
    while (jj >= 0 && jj < s.size())
    {
        if (s[jj] == s[kk])
        {
            jj--;
            kk++;
            len += 2;
        }
        else
        {
            break;
        }
    }
    return s.substr(jj + 1,len);
}

string longestPalindrome(string s) {
    if (s.size() == 0)
        return 0;
    int maxlen = 0;
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        string lenodd = expand(s, i, i);
        string leneven = expand(s, i, i + 1);
        string res = lenodd.size() > leneven.size() ? lenodd : leneven;
        //maxlen = max(maxlen,res);
        if (res.size() > maxlen)
        {
            maxlen =  res.size();
            result = res;
        }
    }
    return result;
}

    
};
// @lc code=end

