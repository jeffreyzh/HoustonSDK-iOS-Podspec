
Pod::Spec.new do |s|

  s.name         = "Houston-Open"
  s.version      = "0.0.2.1"
  s.summary      = "a Houston SDK for iOS."

  s.description  = <<-DESC
  control client behavior by issuing the configuration
                   DESC

  s.homepage     = "http://github.com/meili/HoustonSDK-iOS-Podspec"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author             = { "mogujie" => "mopen@meili-inc.com" }

  s.platform     = :ios
  s.platform     = :ios, "8.0"

  #  When using multiple platforms
  s.ios.deployment_target = "8.0"
  # s.osx.deployment_target = "10.7"
  # s.watchos.deployment_target = "2.0"
  # s.tvos.deployment_target = "9.0"

  s.source       = { :git => "http://github.com/meili/HoustonSDK-iOS-Podspec", :tag => "#{s.version}" }

  s.source_files = "Houston-Open/Classes/**/*"
  s.private_header_files = "Houston-Open/Classes/Private/*.h"

  s.ios.vendored_libraries = 'libHouston-Open.a'

  s.requires_arc = true

  s.dependency 'MWP-iOS-Open'
  s.dependency 'MLComm-Open'
  s.dependency 'Objective-LevelDB'

end
