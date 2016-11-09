/*
 * CodeWriter.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_CODE_GENERATOR_H
#define XSC_CODE_GENERATOR_H


#include <ostream>
#include <stack>


namespace Xsc
{


// Output code writer.
class CodeWriter
{
    
    public:
        
        struct Options
        {
            Options() = default;
            Options(bool enableNewLine, bool enableTabs) :
                enableNewLine   { enableNewLine },
                enableTabs      { enableTabs    }
            {
            }

            bool enableNewLine  = true;
            bool enableTabs     = true;
        };

        CodeWriter(const std::string& indentTab);

        // \throws std::runtime_error If stream is invalid.
        void OutputStream(std::ostream& stream);

        void PushIndent();
        void PopIndent();

        void PushOptions(const Options& options);
        void PopOptions();

        void BeginLine();
        void EndLine();

        void Write(const std::string& text);
        void WriteLine(const std::string& text);

        Options CurrentOptions() const;

    private:
        
        std::ostream*   stream_ = nullptr;
        std::string     indentTab_;
        std::string     indent_;

        std::stack<Options> optionsStack_;

};


} // /namespace Xsc


#endif



// ================================================================================