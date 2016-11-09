/*
 * Report.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_REPORT_H
#define XSC_REPORT_H


#include "Export.h"
#include <stdexcept>
#include <string>


namespace Xsc
{


//! Report exception class.
class HTLIB_EXPORT Report : public std::exception
{
    
    public:
        
        //! Report types enumeration.
        enum class Types
        {
            Info,       //!< Standard information.
            Warning,    //!< Warning message.
            Error       //!< Error message.
        };

        Report(const Report&) = default;
        Report& operator = (const Report&) = default;

        Report(const Types type, const std::string& message);
        Report(const Types type, const std::string& message, const std::string& line, const std::string& marker);

        //! Overrides the 'std::exception::what' function.
        const char* what() const throw() override;

        //! Returns the type of this report.
        inline Types Type() const
        {
            return type_;
        }

        //! Returns the message string.
        inline const std::string& Message() const
        {
            return message_;
        }

        //! Returns the line string where the report occured. This line never has new-line characters at its end.
        inline const std::string& Line() const
        {
            return line_;
        }

        //! Returns the line marker string to highlight the area where the report occured.
        inline const std::string& Marker() const
        {
            return marker_;
        }

        /**
        \brief Returns true if this report has a line with line marker.
        \see Line
        \see Marker
        */
        inline bool HasLine() const
        {
            return (!line_.empty());
        }

    private:

        Types       type_       = Types::Info;
        std::string message_;
        std::string line_;
        std::string marker_;

};


} // /namespace Xsc


#endif



// ================================================================================