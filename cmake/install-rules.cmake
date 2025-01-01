install(
    TARGETS temperature-converter_exe
    RUNTIME COMPONENT temperature-converter_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
