// 3D Vec3s, completely inlined


//--------------------------------------------------
//
//  3D Vec3 class for chromeball
//
//--------------------------------------------------

#include <cmath>

#ifndef ___Vec3_H____
#define ___Vec3_H____



/*!
 *  This is a fully inlined class for Vec3 manipulation in 3D
 */
class Vec3
{


  public:


    Vec3()
    {
       m_Data[0] = 0;
       m_Data[1] = 0;
       m_Data[2] = 0;
    }

    Vec3( const double& v1, const double& v2, const double& v3 )
    {
       m_Data[0] = v1;
       m_Data[1] = v2;
       m_Data[2] = v3;
    }

    Vec3( const double v[3] )
    {
       m_Data[0] = v[0];
       m_Data[1] = v[1];
       m_Data[2] = v[2];
    }

    // copy constructor
    Vec3( const Vec3& v )
    {
       m_Data[0] = v.m_Data[0];
       m_Data[1] = v.m_Data[1];
       m_Data[2] = v.m_Data[2];
    }

   ~Vec3(){}



    //----------------------------------------------------------------
    //
    // Set and get methods
    //
    //----------------------------------------------------------------

    void set( const double& v1, const double& v2, const double& v3 )
    {
       m_Data[0] = v1;
       m_Data[1] = v2;
       m_Data[2] = v3;
    }


    void get( double& v1, double& v2, double& v3 ) const
    {
       v1 = m_Data[0];
       v2 = m_Data[1];
       v3 = m_Data[2];
    }

    void set ( const int index, const double value ) { m_Data[index] = value; }
    void setX( const double value )                  { m_Data[0] = value; }
    void setY( const double value )                  { m_Data[1] = value; }
    void setZ( const double value )                  { m_Data[2] = value; }


    void get( const int index, double& value ) const { value = m_Data[index]; }
    const double get ( const int index ) const       { return m_Data[index]; }
    const double getX() const                        { return m_Data[0]; }
    const double getY() const                        { return m_Data[1]; }
    const double getZ() const                        { return m_Data[2]; }


    const double operator() ( const int& a ) const   { return m_Data[a]; }
    double&      operator[] ( const int& a )         { return m_Data[a]; }
    const double& operator[] ( const int& a ) const { return m_Data[a]; }



    //------------------------------------------------------------------------
    //
    // operator overloads for linear space math: inner product, cross product
    //
    //------------------------------------------------------------------------

    //! inner (dot) product
    const double operator* ( const Vec3& v ) const
    {
        return ( m_Data[0]*v.m_Data[0] 
               + m_Data[1]*v.m_Data[1] 
               + m_Data[2]*v.m_Data[2] );
    }

    //! cross product  ( NOT outer product )
    const Vec3 operator^ (const Vec3& v ) const
    {
       return Vec3(
                      m_Data[1]*v.m_Data[2] - m_Data[2]*v.m_Data[1],
                      m_Data[2]*v.m_Data[0] - m_Data[0]*v.m_Data[2],
                      m_Data[0]*v.m_Data[1] - m_Data[1]*v.m_Data[0]
                    );
    }


    //-------------------------------------------------------------------------
    //
    // operator= and related overloads
    //
    //-------------------------------------------------------------------------

    Vec3& operator= ( const Vec3& v )
    {
        m_Data[0] = v.m_Data[0];
        m_Data[1] = v.m_Data[1];
        m_Data[2] = v.m_Data[2];
	return *this;
    }

    Vec3& operator= ( const double v )
    {
        m_Data[0] = v;
        m_Data[1] = v;
        m_Data[2] = v;
	return *this;
    }
    
    Vec3& operator+= ( const Vec3& v )
    {
        m_Data[0] += v.m_Data[0];
        m_Data[1] += v.m_Data[1];
        m_Data[2] += v.m_Data[2];
        return *this;
    }
   
    Vec3& operator+= ( const double v )
    {
        m_Data[0] += v;
        m_Data[1] += v;
        m_Data[2] += v;
        return *this;
    }
   
    Vec3& operator-= ( const Vec3& v )
    {
        m_Data[0] -= v.m_Data[0];
        m_Data[1] -= v.m_Data[1];
        m_Data[2] -= v.m_Data[2];
        return *this;
    }

    Vec3& operator-= ( const double v )
    {
        m_Data[0] -= v;
        m_Data[1] -= v;
        m_Data[2] -= v;
        return *this;
    }

    Vec3& operator*= ( const double& v )
    {
        m_Data[0] *= v;
        m_Data[1] *= v;
        m_Data[2] *= v;
        return *this;
    }

    Vec3& operator/= ( const double& v )
    {
        m_Data[0] /= v;
        m_Data[1] /= v;
        m_Data[2] /= v;
        return *this;
    }

    Vec3 operator* ( const double& v ) const
    {
        return Vec3( m_Data[0]*v, m_Data[1]*v, m_Data[2]*v );
    }

    Vec3 operator/ ( const double& v ) const
    {
        return Vec3( m_Data[0]/v, m_Data[1]/v, m_Data[2]/v );
    }

    Vec3 operator+ ( const Vec3& v ) const
    {
        return Vec3( m_Data[0] + v.m_Data[0], 
                       m_Data[1] + v.m_Data[1], 
                       m_Data[2] + v.m_Data[2] );

    }

    Vec3 operator- ( const Vec3& v ) const
    {
        return Vec3( m_Data[0] - v.m_Data[0], 
                       m_Data[1] - v.m_Data[1], 
                       m_Data[2] - v.m_Data[2] );

    }

    friend Vec3 operator* ( const double v, const Vec3& V )
    {
        return V*v;
    }

    friend Vec3 operator- ( const Vec3& V ) { return V*(-1.0); }


    //--------------------------------------------------------------------
    //
    //  Other utilities 
    //
    //--------------------------------------------------------------------

    const double magnitude() const { return std::sqrt( m_Data[0]*m_Data[0] 
                                                     + m_Data[1]*m_Data[1]
                                                     + m_Data[2]*m_Data[2] ); }

    void normalize()
    {
        const double mag = magnitude();
        m_Data[0] /= mag;    
        m_Data[1] /= mag;    
        m_Data[2] /= mag;    
    }

    const Vec3 normal() const { return (*this)/magnitude(); }

    const Vec3 rotate(const Vec3& axis, const double angle)
    {
       Vec3 a = axis.normal();
       double ca = std::cos(angle);
       double sa = std::sin(angle);
       Vec3 result = (*this)*ca + a*(a*(*this))*(1.0-ca) + (a^(*this))*sa;
       return result;
    }

  private:

    double m_Data[3];


};

//typedef used to specify variable purposes
typedef Vec3 Point3;


struct Color { double r, g, b; };



#endif


