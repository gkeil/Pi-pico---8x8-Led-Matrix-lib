# Add library and the correspondin source files
# an INTERFACE Library is produce. No lib object is generated.
# In order to use this library the liblcd folder must be included
# with add_subdirectory()

# prevent multiple definitions
if ( NOT TARGET led8x8 )

    add_library( led8x8 INTERFACE )

    target_sources( led8x8 INTERFACE    
                                        max7219.c
                                        pico_port.c
                                     
                                    )

    target_include_directories(led8x8 INTERFACE ../include/)

    # Add the standard library to the build
    target_link_libraries(  led8x8     INTERFACE
                            pico_stdlib
                            hardware_spi
                            
    )

endif()