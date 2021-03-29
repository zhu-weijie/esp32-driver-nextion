#ifndef __NEXTION_COMPONENT_H__
#define __NEXTION_COMPONENT_H__

#include <stdbool.h>
#include <stdint.h>
#include "base/codes.h"
#include "base/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Refreshes a component, bringing it to front.
     * @param handle Nextion context pointer.
     * @param component_name_or_id A null-terminated string with the component's name or id.
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_refresh(nextion_handle_t handle, const char *component_name_or_id);

    /**
     * @brief Set a component visibility.
     *
     * @param handle Nextion context pointer.
     * @param component_name_or_id A null-terminated string with the component's name or id.
     * @param visible_or_not True make it visible; false make it invisible.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_visibility(nextion_handle_t handle,
                                               const char *component_name_or_id,
                                               bool visible_or_not);

    /**
     * @brief Set all components visibility.
     *
     * @note Only for the current page.
     *
     * @param handle Nextion context pointer.
     * @param visible_or_not True make them visible; false make them invisible.
     *
     * @return NEX_OK or NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_visibility_all(nextion_handle_t handle, bool visible_or_not);

    /**
     * @brief Set if a component can respond to touch events or not.
     *
     * @param handle Nextion context pointer.
     * @param component_name_or_id A null-terminated string with the component's name or id.
     * @param touchable_or_not True make it touchable; false make it untouchable.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_touchable(nextion_handle_t handle,
                                              const char *component_name_or_id,
                                              bool touchable_or_not);

    /**
     * @brief Set if all components can respond to touch events or not.
     *
     * @note Only for the current page.
     *
     * @param handle Nextion context pointer.
     * @param touchable_or_not True make them touchable; false make them untouchable.
     *
     * @return NEX_OK or NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_touchable_all(nextion_handle_t handle, bool touchable_or_not);

    /**
     * @brief Get a component ".txt" value.
     * @note Shorthand for "nextion_component_get_property_text" using "txt" property.
     * @details It's the caller responsibility to allocate a buffer big enough to
     * hold the text returned.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param[in] buffer Location where the retrieved text will be stored. Must take the null-terminator into account.
     * @param[in] expected_length Expected text length that might be retrieved. Will be update with the retrieved text length.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_get_text(nextion_handle_t handle,
                                         const char *component_name,
                                         char *buffer,
                                         size_t *expected_length);

    /**
     * @brief Get a component ".val" value.
     * @note Shorthand for "nextion_component_get_property_number" using "val" property.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param[in] number Location where the retrieved number will be stored.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_get_value(nextion_handle_t handle,
                                          const char *component_name,
                                          int32_t *number);

    /**
     * @brief Get a component ".val" value converted to boolean.
     * @note Shorthand for "nextion_component_get_property_number" using "val" property
     * and converting to boolean.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param[in] value Location where the retrieved boolean will be stored.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_get_boolean(nextion_handle_t handle,
                                            const char *component_name,
                                            bool *value);

    /**
     * @brief Set a component ".txt" value.
     * @note Shorthand for "nextion_component_set_property_text" using "txt" property.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param[in] text A null-terminated string with the text.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_text(nextion_handle_t handle,
                                         const char *component_name,
                                         char *text);

    /**
     * @brief Set a component ".val" value.
     * @note Shorthand for "nextion_component_set_property_number" using "val" property.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param[in] number Value to be sent.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_value(nextion_handle_t handle,
                                          const char *component_name,
                                          int32_t number);

    /**
     * @brief Set a component ".val" value, converted as boolean.
     * @note Shorthand for "nextion_component_set_property_number" using "val" property
     * and converting to boolean.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param[in] value Value to be sent.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_boolean(nextion_handle_t handle,
                                            const char *component_name,
                                            bool value);

    /**
     * @brief Get a text from a component property.
     *
     * @details It's the caller responsibility to allocate a buffer big enough to
     * hold the text returned.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param property_name A null-terminated string with the property name to retrieve the text from.
     * @param[in] buffer Location where the retrieved text will be stored. Must take the null-terminator into account.
     * @param[in] expected_length Expected text length that might be retrieved. Will be update with the retrieved text length.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_get_property_text(nextion_handle_t handle,
                                                  const char *component_name,
                                                  const char *property_name,
                                                  char *buffer,
                                                  size_t *expected_length);

    /**
     * @brief Get a number from a component property.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param property_name A null-terminated string with the property name to retrieve the number from.
     * @param[in] number Location where the retrieved number will be stored.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_get_property_number(nextion_handle_t handle,
                                                    const char *component_name,
                                                    const char *property_name,
                                                    int32_t *number);

    /**
     * @brief Set a component property with text.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param property_name A null-terminated string with the property name to set the text.
     * @param[in] text A null-terminated string with the text.
     * @param text_length Text lenght.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_property_text(nextion_handle_t handle,
                                                  const char *component_name,
                                                  const char *property_name,
                                                  char *text);

    /**
     * @brief Set a component property with number.
     *
     * @param handle Nextion context pointer.
     * @param component_name A null-terminated string with the component name.
     * @param property_name A null-terminated string with the property name to set the value.
     * @param[in] number Value to be sent.
     *
     * @return NEX_OK or NEX_FAIL | NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE | NEX_DVC_ERR_INVALID_COMPONENT.
     */
    nex_err_t nextion_component_set_property_number(nextion_handle_t handle,
                                                    const char *component_name,
                                                    const char *property_name,
                                                    int32_t number);

#ifdef __cplusplus
}
#endif

#endif //__NEXTION_COMPONENT_H__