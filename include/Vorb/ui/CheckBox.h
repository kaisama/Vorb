//
// CheckBox.h
// Vorb Engine
//
// Created by Benjamin Arnold on 6 May 2015
// Copyright 2014 Regrowth Studios
// MIT License
//

/*! \file CheckBox.h
* \brief 
* Defines the CheckBox widget.
*
*/

#pragma once

#ifndef Vorb_CheckBox_h__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_CheckBox_h__
//! @endcond

#ifndef VORB_USING_PCH
#include "Vorb/types.h"
#endif // !VORB_USING_PCH

#include "Vorb/ui/Drawables.h"
#include "Vorb/ui/Widget.h"

namespace vorb {
    namespace ui {

        /// Forward Declarations
        class UIRenderer;

        class CheckBox : public Widget {
            friend class CheckBoxScriptFuncs;
        public:
            /*! \brief Default constructor. */
            CheckBox();
            /*! \brief Default destructor. */
            virtual ~CheckBox();

            /*! \brief Initialiser for general set-up. */
            virtual void initBase() override;

            /*! \brief Adds all drawables to the UIRenderer */
            virtual void addDrawables() override;
            /*! \brief Refresh drawables. */
            virtual void refreshDrawables() override;

            virtual void check();
            virtual void uncheck();
            virtual void toggleChecked();

            /************************************************************************/
            /* Getters                                                              */
            /************************************************************************/
            virtual      const VGTexture& getUncheckedTexture()     const { return m_uncheckedTexture;            }
            virtual      const VGTexture& getCheckedTexture()       const { return m_checkedTexture;              }
            virtual const vg::SpriteFont* getFont()                 const { return m_drawableText.getFont();      }
            virtual         const color4& getBoxColor()             const { return m_boxColor;                    }
            virtual         const color4& getBoxHoverColor()        const { return m_boxHoverColor;               }
            virtual         const color4& getBoxCheckedColor()      const { return m_boxCheckedColor;             }
            virtual         const color4& getBoxCheckedHoverColor() const { return m_boxCheckedHoverColor;        }
            virtual         const color4& getTextColor()            const { return m_textColor;                   }
            virtual         const color4& getTextHoverColor()       const { return m_textHoverColor;              }
            virtual        const nString& getText()                 const { return m_drawableText.getText();      }
            virtual  const vg::TextAlign& getTextAlign()            const { return m_drawableText.getTextAlign(); }
            virtual          const f32v2& getTextScale()            const { return m_drawableText.getTextScale(); }
            virtual           const bool& isChecked()               const { return m_isChecked;                   }

            /************************************************************************/
            /* Setters                                                              */
            /************************************************************************/
            virtual void setFont(const vg::SpriteFont* font);
            virtual void setCheckedTexture(VGTexture texture);
            virtual void setUncheckedTexture(VGTexture texture);
            virtual void setBoxColor(const color4& color);
            virtual void setBoxHoverColor(const color4& color);
            virtual void setBoxCheckedColor(const color4& color);
            virtual void setBoxCheckedHoverColor(const color4& color);
            virtual void setText(const nString& text);
            virtual void setTextColor(const color4& color);
            virtual void setTextHoverColor(const color4& color);
            virtual void setTextAlign(vg::TextAlign textAlign);
            virtual void setTextScale(const f32v2& textScale);
            virtual void setChecked(bool checked);

            /************************************************************************/
            /* Events                                                               */
            /************************************************************************/
            Event<bool> ValueChange; ///< Occurs when value of the box is changed

        protected:
            virtual void calculateDrawables() override;

            /*! Updates the colours set for the drawables. */
            virtual void updateColor();
            /*! Updates the text position in the drawable. */
            virtual void updateTextPosition();

            /************************************************************************/
            /* Event Handlers                                                       */
            /************************************************************************/
            virtual void onMouseUp(Sender s, const MouseButtonEvent& e) override;
            virtual void onMouseMove(Sender s, const MouseMotionEvent& e) override;

            /************************************************************************/
            /* LUA Callbacks                                                        */
            /************************************************************************/
#ifdef VORB_USING_SCRIPT
            std::vector<script::Function> m_valueChangeFuncs;
#endif

            /************************************************************************/
            /* Members                                                              */
            /************************************************************************/
            DrawableRect          m_drawableRect, m_drawnRect;
            DrawableText          m_drawableText, m_drawnText;
            color4                m_boxColor,        m_boxHoverColor;
            color4                m_boxCheckedColor, m_boxCheckedHoverColor;
            color4                m_textColor,       m_textHoverColor;
            const vg::SpriteFont* m_defaultFont;
            VGTexture             m_checkedTexture, m_uncheckedTexture;
            bool                  m_isChecked;
        };
    }
}
namespace vui = vorb::ui;

#endif // !Vorb_CheckBox_h__
